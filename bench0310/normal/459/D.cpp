#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1000005;
vector<int> tree(4*N,0);

void update(int idx,int l,int r,int pos)
{
    if(l==r) tree[idx]++;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos);
        else update(2*idx+1,m+1,r,pos);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> v(n+1,0);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    vector<int> l(n+1,0);
    vector<int> r(n+1,0);
    map<int,int> m;
    for(int i=1;i<=n;i++) l[i]=++m[v[i]];
    m.clear();
    for(int i=n;i>=1;i--) r[i]=++m[v[i]];
    ll res=0;
    for(int i=n;i>=1;i--)
    {
        res+=query(1,1,n,1,l[i]-1);
        update(1,1,n,r[i]);
    }
    printf("%I64d\n",res);
    return 0;
}