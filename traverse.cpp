#include <iostream>
#include <stack>
#include <utility>
using namespace std;

struct tnode 
{
    int value;
    tnode* left;
    tnode* right;
    tnode(int v, tnode* l, tnode* r)
    {
        value = v;
        left = l;
        right = r;
    }
};


void traverse_pre1(tnode* root)
{
    if(root == NULL)
        return;

    cout<<root->value<<endl;
    if(root->left != NULL)
        traverse_pre1(root->left);
    if(root->right != NULL)
        traverse_pre1(root->right);

    return;
}

void traverse_post1(tnode* root)
{
    if(root == NULL)
        return;

    if(root->left != NULL)
        traverse_post1(root->left);
    if(root->right != NULL)
        traverse_post1(root->right);
    cout<<root->value<<endl;

    return;
}

void traverse_mid1(tnode* root)
{
    if(root == NULL)
        return;

    if(root->left != NULL)
        traverse_mid1(root->left);

    cout<<root->value<<endl;

    if(root->right != NULL)
        traverse_mid1(root->right);

    return;
}

void traverse_pre22(tnode* root)
{
    if(root == NULL)
        return;

    stack<tnode*> s;
    s.push(root);
    while(!s.empty())
    {
        tnode* cut = s.top();
        s.pop();
        cout<<cut->value<<endl;

        if (cut->right)
            s.push(cut->right);
        if (cut->left)
            s.push(cut->left);
    }


    return;
}

void traverse_pre2(tnode* root)
{
    if(root == NULL)
        return;

    stack<tnode*> s;
    tnode* cut = root;  
    while(cut || !s.empty())
    {
        while(cut)
        {
            s.push(cut);
            cout<<cut->value<<endl;
            cut = cut->left;
        }
        cut = s.top();
        s.pop();
        cut = cut->right;
    }
    return;
}

void traverse_mid2(tnode* root)
{
    if(root == NULL)
        return;

    stack<tnode*> s;
    tnode* cut = root;  
    while(cut || !s.empty())
    {
        while(cut)
        {
            s.push(cut);
            cut = cut->left;
        }
        cut = s.top();
        s.pop();
        cout<<cut->value<<endl;;
        cut = cut->right;
    }
}

void traverse_post2(tnode* root)
{
    stack< pair<tnode*, bool> > s;
    s.push(make_pair(root, false));
    bool visited;
    while(!s.empty())
    {
        root = s.top().first;
        visited = s.top().second;
        s.pop();
        if(root ==NULL)
            continue;
        if(visited)
            cout<<root->value<<endl;
        else
        {
            s.push( make_pair(root, true));
            s.push( make_pair(root->right, false));
            s.push( make_pair(root->left, false));
            /* 中序 : 右中左
             * 前序 : 右左中
            */
        }

    }
}


int main()
{
    tnode n1 = tnode(1,NULL,NULL); 
    tnode n3 = tnode(3,NULL,NULL); 
    tnode n2 = tnode(2,&n1,&n3); 

    tnode n5 = tnode(5,NULL,NULL); 
    tnode n7 = tnode(7,NULL,NULL); 
    tnode n6 = tnode(6,&n5,&n7); 
    tnode n4 = tnode(4,&n2,&n6); 
  
    /*
    traverse_pre1(&n4);
    cout<<endl;
    traverse_pre2(&n4);
    cout<<endl;
    */

    traverse_mid1(&n4);
    cout<<endl;

    traverse_mid2(&n4);
    cout<<endl;

    traverse_post1(&n4);
    cout<<endl;

    traverse_post2(&n4);

    return 0;
}
