#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node
{
    int mx;
    Node *l,*r;
    Node(){mx=0;l=r=nullptr;}
    void upd(){mx=max((l?l->mx:0),(r?r->mx:0));}
};

void update(Node *now,int l,int r,int pos,int val)
{
    if(l==r) now->mx=max(now->mx,val);
    else
    {
        int m=(l+r)/2;
        if(pos<=m)
        {
            if(!(now->l)) now->l=new Node();
            update(now->l,l,m,pos,val);
        }
        else
        {
            if(!(now->r)) now->r=new Node();
            update(now->r,m+1,r,pos,val);
        }
        now->upd();
    }
}

int query(Node *now,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return now->mx;
    int m=(l+r)/2;
    int res=0;
    if(now->l) res=max(res,query(now->l,l,m,ql,min(qr,m)));
    if(now->r) res=max(res,query(now->r,m+1,r,max(ql,m+1),qr));
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=100000;
    int n,m;
    cin >> n >> m;
    vector<Node*> root(n+1,0);
    for(int i=1;i<=n;i++) root[i]=new Node();
    int res=0;
    while(m--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        int best=query(root[a],0,N,0,c-1)+1;
        update(root[b],0,N,c,best);
        res=max(res,best);
    }
    cout << res << "\n";
    return 0;
}