#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<array<int,2>> tree(4*N,{0,0});
vector<int> a(N,0);

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]={a[l],l};
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
}

array<int,2> query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return {0,0};
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return max(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n-1;i++) cin >> a[i];
    a[n]=n;
    build(1,1,n);
    vector<ll> dp(n+1,0);
    ll res=0;
    for(int i=n-1;i>=1;i--)
    {
        int m=query(1,1,n,i+1,a[i])[1];
        dp[i]=dp[m]+(m-i)+(n-m)-(a[i]-m);
        res+=dp[i];
    }
    cout << res << "\n";
    return 0;
}