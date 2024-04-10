#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node
{
    int val;
    Node *l,*r;
    Node(){val=0;l=r=nullptr;}
};

void update(Node *now,int l,int r,int pos,int val)
{
    if(l==r) now->val+=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m)
        {
            if(!now->l) now->l=new Node();
            update(now->l,l,m,pos,val);
        }
        else
        {
            if(!now->r) now->r=new Node();
            update(now->r,m+1,r,pos,val);
        }
        now->val=(now->l?now->l->val:0)+(now->r?now->r->val:0);
    }
}

int query(Node *now,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return now->val;
    int m=(l+r)/2;
    int res=0;
    if(now->l) res+=query(now->l,l,m,ql,min(qr,m));
    if(now->r) res+=query(now->r,m+1,r,max(ql,m+1),qr);
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=1000000000;
    const int M=10000;
    vector<Node*> root(M+1,0);
    for(int i=1;i<=M;i++) root[i]=new Node();
    int n,k;
    cin >> n >> k;
    vector<array<int,3>> v(n);
    for(int i=0;i<n;i++) cin >> v[i][1] >> v[i][0] >> v[i][2];
    sort(v.begin(),v.end());
    for(auto [r,x,f]:v) update(root[f],1,N,x,1);
    ll res=0;
    for(auto [r,x,f]:v)
    {
        update(root[f],1,N,x,-1);
        for(int i=max(1,f-k);i<=min(M,f+k);i++) res+=query(root[i],1,N,max(1,x-r),min(N,x+r));
    }
    cout << res << "\n";
    return 0;
}