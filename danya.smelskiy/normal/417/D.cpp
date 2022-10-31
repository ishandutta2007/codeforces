#include <bits/stdc++.h>
using namespace std;

int n,m;
long long b;
pair<long long,pair<long long,long long> > a[105];
long long dp[(1<<20)+5];
int k,x;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>b;
    for (int i=1;i<=n;++i) {
        cin>>a[i].second.first>>a[i].first;
        cin>>k;
        int mask=0;
        for (int j=1;j<=k;++j) {
            cin>>x;
            --x;
            mask|=(1<<x);
        }
        a[i].second.second=mask;
    }
    sort(a+1,a+n+1);
    for (int i=0;i<(1<<m);++i)
        dp[i]=2e18;
    dp[0]=0;
    long long ans=2e18;
    for (int i=1;i<=n;++i) {
        int mask=a[i].second.second;
        for (int j=0;j<(1<<m);++j) {
            dp[j]=min(dp[j],dp[(j|mask)^mask]+a[i].second.first);
        }
        ans=min(ans,dp[(1<<m)-1]+a[i].first*b);
    }
    if (ans>=2e18) cout<<"-1"; else
    cout<<ans;
}