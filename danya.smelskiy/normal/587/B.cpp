#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
vector<long long> q;
long long n,k,l;
long long a[1000005];
map<long long,long long> to;
long long ans;
vector<long long> dp[1000005];
long long dp2[1000005];
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>l>>k;
    for (long long i=1;i<=n;++i)
        dp[i].resize(k+1);
    for (long long i=1;i<=n;++i){
        cin>>a[i];
        q.push_back(a[i]);
    }
    sort(q.begin(),q.end());
    long long last=0;
    for (long long i=0;i<q.size();++i){
        if (i==0 || q[i]!=q[i-1]) ++last;
        to[q[i]]=last;
    }
    for (long long i=1;i<=n;++i)
        a[i]=to[a[i]];
    for (long long i=1;i<=n;++i)
        dp[i][1]=1;
    for (long long i=2;i<=k;++i) {
        for (long long j=1;j<=last;++j)
            dp2[j]=0;
        for (long long j=1;j<=n;++j)
            dp2[a[j]]=(dp2[a[j]]+dp[j][i-1])%md;
        for (long long j=1;j<=last;++j)
            dp2[j]=(dp2[j]+dp2[j-1])%md;
        for (long long j=1;j<=n;++j)
            dp[j][i]=dp2[a[j]];
    }
    for (long long i=1;i<=k;++i)
    for (long long j=1;j<=n;++j) {
        long long ll=(l/n) + (j<=l%n ? 1 : 0);
        ll-=i-1;
        if (ll>0)
        ans=(ans+ll%md*dp[j][i])%md;
    }
    cout<<ans;
}