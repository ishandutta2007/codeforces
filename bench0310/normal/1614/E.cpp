#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node
{
    int mn,mx;
    int lazy;
    array<Node*,2> kids;
    Node(int a,int b){mn=a;mx=b;lazy=0;kids[0]=kids[1]=nullptr;}
    void extend(int l,int r)
    {
        if(!kids[0])
        {
            int m=(l+r)/2;
            kids[0]=new Node(l,m);
            kids[1]=new Node(m+1,r);
        }
    }
    void pull()
    {
        mn=kids[0]->mn;
        mx=kids[1]->mx;
    }
    void apply(int x)
    {
        mn+=x;
        mx+=x;
        lazy+=x;
    }
    void push(int l,int r)
    {
        extend(l,r);
        for(Node *to:kids) to->apply(lazy);
        lazy=0;
    }
};

void update(Node *now,int l,int r,int ql,int qr,int x)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) now->apply(x);
    else
    {
        int m=(l+r)/2;
        now->push(l,r);
        update(now->kids[0],l,m,ql,min(qr,m),x);
        update(now->kids[1],m+1,r,max(ql,m+1),qr,x);
        now->pull();
    }
}

int query(Node *now,int l,int r,int pos)
{
    if(l==r) return now->mn;
    int m=(l+r)/2;
    now->push(l,r);
    if(pos<=m) return query(now->kids[0],l,m,pos);
    else return query(now->kids[1],m+1,r,pos);
}

int descend(Node *now,int l,int r,int lim,int tp) //0-[0,lim] 1-[lim,N]
{
    if(l==r) return l;
    int m=(l+r)/2;
    now->push(l,r);
    if(tp==0)
    {
        if(lim<now->kids[1]->mn) return descend(now->kids[0],l,m,lim,tp);
        else return descend(now->kids[1],m+1,r,lim,tp);
    }
    else
    {
        if(now->kids[0]->mx<lim) return descend(now->kids[1],m+1,r,lim,tp);
        else return descend(now->kids[0],l,m,lim,tp);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=int(1e9);
    Node *root=new Node(0,N);
    int n;
    cin >> n;
    int res=0;
    while(n--)
    {
        int t;
        cin >> t;
        if(query(root,0,N,0)<=t-1)
        {
            int p=descend(root,0,N,t-1,0);
            update(root,0,N,0,p,1);
        }
        if(query(root,0,N,N)>=t+1)
        {
            int p=descend(root,0,N,t+1,1);
            update(root,0,N,p,N,-1);
        }
        int q;
        cin >> q;
        while(q--)
        {
            int p;
            cin >> p;
            p=(p+res)%(N+1);
            res=query(root,0,N,p);
            cout << res << "\n";
        }
    }
    return 0;
}