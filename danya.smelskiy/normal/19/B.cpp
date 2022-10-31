#include <bits/stdc++.h>
using namespace std;

long long n;
long long x,y;
long long ans;
long long dp[2005];

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (long long i=1;i<=n;++i)
        dp[i]=1e18;
    for (long long i=1;i<=n;++i) {
        cin>>x>>y;
        ++x;
        ans+=y;
        for (long long j=n-1;j>=0;--j) {
            long long nxt = (j+x > n ? n : j+x);
            dp[nxt]=min(dp[nxt],dp[j]+y);
        }
    }
    cout<<min(dp[n],ans);
}