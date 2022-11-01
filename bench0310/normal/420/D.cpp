#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
typedef long long ll;

struct Node;
using twoNodes=array<Node*,2>;

struct Node
{
    int val;
    int sz;
    twoNodes kids;
    Node *p;
    Node(int a){val=a;sz=1;kids[0]=kids[1]=p=nullptr;}
};

int sz(Node *me){return (me?me->sz:0);}
int side(Node *me){return (me->p?(me->p->kids[1]==me):0);}

void recalc(Node *me)
{
    if(!me) return;
    me->sz=1;
    for(Node *to:me->kids) if(to) me->sz+=to->sz;
}

void make_parent(Node *me,int id,Node *kid)
{
    if(me) me->kids[id]=kid;
    recalc(me);
    if(kid) kid->p=me;
}

void rotate_up(Node *me)
{
    Node *p=me->p;
    int id=side(me);
    make_parent(p->p,side(p),me);
    make_parent(p,id,me->kids[id^1]);
    make_parent(me,id^1,p);
}

void splay(Node *me)
{
    while(me->p)
    {
        if(me->p->p)
        {
            if(side(me)==side(me->p)) rotate_up(me->p);
            else rotate_up(me);
        }
        rotate_up(me);
    }
}

Node* find_kth(Node *me,int cnt)
{
    if(sz(me->kids[0])>=cnt) return find_kth(me->kids[0],cnt);
    else if(sz(me->kids[0])==cnt-1) return me;
    else return find_kth(me->kids[1],cnt-sz(me->kids[0])-1);
}

twoNodes split(Node *me,int cnt)
{
    if(cnt==0) return {nullptr,me};
    Node* one=find_kth(me,cnt);
    splay(one);
    Node *two=one->kids[1];
    one->kids[1]=nullptr;
    if(two) two->p=nullptr;
    recalc(one);
    return {one,two};
}

Node* tmerge(Node *a,Node *b)
{
    if(!a) return b;
    a=find_kth(a,sz(a));
    splay(a);
    make_parent(a,1,b);
    return a;
}

int pos(Node *me)
{
    splay(me);
    return (1+sz(me->kids[0]));
}

void print(Node *me)
{
    if(!me) return;
    print(me->kids[0]);
    cout << me->val << " ";
    print(me->kids[1]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,2>> v(m);
    for(int i=0;i<m;i++) cin >> v[i][0] >> v[i][1];
    auto out=[](){cout << "-1\n";exit(0);};
    Node *root=nullptr;
    vector<Node*> a(n+1,nullptr);
    int cnt=0;
    for(auto [x,y]:v)
    {
        if(a[x]==nullptr)
        {
            if(cnt>=y) out();
            a[x]=new Node(x);
            root=tmerge(a[x],root);
            cnt++;
        }
        else
        {
            int p=pos(a[x]);
            root=a[x];
            if(p!=y) out();
            auto [one,tmp]=split(root,p-1);
            auto [two,three]=split(tmp,1);
            root=tmerge(tmerge(two,one),three);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==nullptr)
        {
            a[i]=new Node(i);
            root=tmerge(root,a[i]);
        }
    }
    reverse(v.begin(),v.end());
    for(auto [x,y]:v)
    {
        if(pos(a[x])!=1) out();
        root=a[x];
        auto [one,tmp]=split(root,1);
        auto [two,three]=split(tmp,y-1);
        root=tmerge(tmerge(two,one),three);
    }
    print(root);
    cout << "\n";
    return 0;
}