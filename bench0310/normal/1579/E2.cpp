#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> tree(4*N,0);

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r) tree[idx]+=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        vector<array<int,2>> h;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            h.push_back({a[i],i});
        }
        sort(h.begin(),h.end());
        int id=1;
        for(int i=0;i<n;i++)
        {
            if(i>0&&h[i][0]!=h[i-1][0]) id++;
            a[h[i][1]]=id;
        }
        ll res=0;
        for(int i=1;i<=n;i++)
        {
            res+=min(query(1,1,n,1,a[i]-1),query(1,1,n,a[i]+1,n));
            update(1,1,n,a[i],1);
        }
        for(int i=1;i<=n;i++) update(1,1,n,a[i],-1);
        cout << res << "\n";
    }
    return 0;
}