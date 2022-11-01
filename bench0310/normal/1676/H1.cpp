#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> tree(4*N,0);

void update(int idx,int l,int r,int pos,int x)
{
    tree[idx]+=x;
    if(l<r)
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,x);
        else update(2*idx+1,m+1,r,pos,x);
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<array<int,2>> v(n);
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            v[i-1]={a,-i};
        }
        ranges::sort(v);
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) p[-v[i-1][1]]=i;
        ll res=0;
        for(int i=1;i<=n;i++)
        {
            res+=query(1,1,n,p[i]+1,n);
            update(1,1,n,p[i],1);
        }
        for(int i=1;i<=n;i++) update(1,1,n,p[i],-1);
        cout << res << "\n";
    }
    return 0;
}