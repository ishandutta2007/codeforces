#include <bits/stdc++.h>
using namespace std;

long long n,m,d;
long long a[200005];
long long b[200005];
long long t[200005];
long long ans=-1e18;
long long dp[200005];
long long dp2[200005];
pair<long long,long long> q[200005];
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>d;
    for (long long i=1;i<=m;++i)
        cin>>a[i]>>b[i]>>t[i];
    t[0]=1;
    for (long long i=1;i<=m;++i) {
        long long ll=t[i]-t[i-1];
        ll=ll*d;
        long long l=0;
        long long r=0;
        for (long long j=1;j<=n;++j) {
            while (l<r && q[r].first<dp[j]) --r;
            ++r;
            q[r]=make_pair(dp[j],j);
            if (q[l+1].second<j-ll) ++l;
            dp2[j]=q[l+1].first;
        }
        for (long long j=1;j<=n;++j) {
            r=j+ll;
            r=min(r,n);
            dp[j]=(b[i]-abs(a[i]-j)+max(dp2[r],dp2[j]));
        }
    }
    for (long long i=1;i<=n;++i)
        ans=max(ans,dp[i]);
    cout<<ans;

}