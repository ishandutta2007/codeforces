#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,s,e;
    cin >> n >> s >> e;
    auto in=[&](vector<ll> &v)
    {
        v.assign(n+1,0);
        for(int i=1;i<=n;i++) cin >> v[i];
    };
    vector<ll> x,a,b,c,d;
    in(x); in(a); in(b); in(c); in(d);
    vector<int> ord(n,0);
    for(int i=0;i<n;i++) ord[i]=i+1;
    sort(ord.begin(),ord.end(),[&](int i,int j){return (x[i]<x[j]);});
    int ts=0,te=0;
    const ll inf=(1ll<<60);
    vector<ll> dp(n+1,inf);
    dp[0]=0;
    auto chmin=[&](ll &i,ll j){i=min(i,j);};
    for(int i:ord)
    {
        vector<ll> ndp(n+1,inf);
        for(int j=0;j<=n;j++)
        {
            if(i!=s&&i!=e)
            {
                //create a new group
                if(j<n&&!(j==1&&ts==1&&te==1)) chmin(ndp[j+1],dp[j]-2*x[i]+b[i]+d[i]);
                //add to the left side of a group
                if(j>=1&&!(j==1&&ts==1)) chmin(ndp[j],dp[j]+b[i]+c[i]);
                //add to the right side of a group
                if(j>=1&&!(j==1&&te==1)) chmin(ndp[j],dp[j]+a[i]+d[i]);
                //merge two groups
                if(j>=2) chmin(ndp[j-1],dp[j]+2*x[i]+a[i]+c[i]);
            }
            else if(i==s)
            {
                //create a new group
                if(j<n) chmin(ndp[j+1],dp[j]-x[i]+d[i]);
                //add to the left side of the first group
                if(j>=1) chmin(ndp[j],dp[j]+x[i]+c[i]);
                ts=1;
            }
            else if(i==e)
            {
                //create a new group
                if(j<n) chmin(ndp[j+1],dp[j]-x[i]+b[i]);
                //add to the right side of the last group
                if(j>=1) chmin(ndp[j],dp[j]+x[i]+a[i]);
                te=1;
            }
        }
        dp=ndp;
    }
    cout << dp[1] << "\n";
    return 0;
}