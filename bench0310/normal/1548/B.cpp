#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<ll> d(N,0);
vector<ll> tree(4*N,0);

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=d[l];
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=gcd(tree[2*idx],tree[2*idx+1]);
    }
}

ll query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return gcd(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
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
        vector<ll> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        if(n==1)
        {
            cout << "1\n";
            continue;
        }
        for(int i=1;i<n;i++) d[i]=abs(a[i+1]-a[i]);
        build(1,1,n-1);
        int r=1;
        int res=1;
        for(int l=1;l<n;l++)
        {
            r=max(r,l);
            while(r+1<n&&query(1,1,n-1,l,r+1)>1) r++;
            if(d[l]>1) res=max(res,r-l+2);
        }
        cout << res << "\n";
    }
    return 0;
}