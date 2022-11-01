#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXLEN = 300000;
struct node
{
    int val, rd, size;
    node *child[2];
};
struct Pr
{
    char c;
    int pos;
}W[MAXLEN];
typedef node *Node;
Node Root[27], Null, q[MAXLEN * 2];
int N, Cop, t, w, len, Tot;
char str[MAXLEN];

void update(Node &root)
{
    root->size = root->child[0]->size + root->child[1]->size + 1;
}

void Rotate(Node &root,int p)
{
    Node temp = root->child[p];
    root->child[p] = temp->child[p ^ 1];
    temp->child[p ^ 1] = root;
    update(root); update(temp);
    root = temp;    
}

void Insert(Node &root,int val)
{
    if (root == Null)
    {
        root = new(node);
        root->child[0] = root->child[1] = Null;
        root->size = 1;
        root->rd = rand();
        root->val = val;
        return;
    }
    if (val < root->val)
    {
        Insert(root->child[0], val);
        if (root->child[0]->rd > root->rd)
            Rotate(root, 0);
    }
    else
    {
        Insert(root->child[1], val);
        if (root->child[1]->rd > root->rd)
            Rotate(root, 1);
    }
    update(root);
}

int Ask(Node &root,int p)
{
    if (root->child[0]->size >= p)
        return Ask(root->child[0], p);
    if (root->child[0]->size + 1 == p)
        return root->val;
    return Ask(root->child[1], p - root->child[0]->size - 1);
}

void Delet(Node &root,int val)
{
    if (root->val == val)
    {
        if (root->child[0] == Null && root->child[1] == Null)
        {
            root = Null;
            return;
        }
        else
        {
            if (root->child[0]->rd > root->child[1]->rd)
            {
                Rotate(root, 0);
                Delet(root->child[1], val);
            }
            else
            {
                Rotate(root, 1);
                Delet(root->child[0], val);
            }
        }
        update(root);
        return ;
    }
    if (val < root->val)
        Delet(root->child[0], val);
    else
        Delet(root->child[1], val);
    update(root);
}

void Init()
{
    Null = new(node);
    Null->size = 0;
    Null->rd = -1;
    for(int i = 0;i <= 'z' - 'a';i++)
        Root[i] = Null;
    scanf("%d\n",&Cop);
    scanf("%s\n",str + 1);
    len = strlen(str + 1);
    for(int i = 1;i <= Cop;i++)
    {
        for(int j = 1;j <= len;j++)
            Insert(Root[str[j] - 'a'], (i - 1) * len + j);
    }
}

int cmp(Pr a,Pr b)
{
    return a.pos < b.pos;
}

void Work()
{
    int p;
    char c;
    scanf("%d\n",&N);
    for(int i = 1;i <= N;i++)
    {
        scanf("%d %c\n",&p,&c);
        int temp = Ask(Root[c - 'a'], p);
        Delet(Root[c - 'a'], temp);
    }
    for(int i = 0;i <= 'z' - 'a';i++)
    {
        t = w = 0;
        q[++w] = Root[i];
        while(t < w)
        {
            Node temp = q[++t];
            if (temp == Null)
                continue;
            W[++Tot] = (Pr){i + 'a', temp->val};
            q[++w] = temp->child[0];
            q[++w] = temp->child[1];
        }
    }
    sort(W + 1,W + Tot + 1,cmp);
    for(int i = 1;i <= Tot;i++)
        printf("%c",W[i].c);
    printf("\n");
}

int main()
{
    Init();
    Work();
    return 0;
}