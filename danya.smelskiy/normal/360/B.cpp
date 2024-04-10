#include <bits/stdc++.h>
using namespace std;



long long n,k;
long long a[2005];
long long dp[2005];
inline bool check(long long mid){
    for (long long i=1;i<=n;++i)
        dp[i]=1e9;
    dp[1]=0;
    for (long long i=1;i<n;++i) {
        dp[i]=min(dp[i],i-1);
        for (long long j=i+1;j<=n;++j) {
            if (j==n) dp[n]=min(dp[n],dp[i]+n-i);
            if (abs(a[j]-a[i])<=(j-i)*mid) dp[j]=min(dp[j],dp[i]+j-i-1);
        }
    }
    return dp[n]<=k;
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    long long l=0;
    long long r=2e9;
    while (l<r-1) {
        long long mid=(l+r)>>1;
        if (check(mid)) r=mid;
        else l=mid;
    }
    cout<< (check(l) ? l : r);
}