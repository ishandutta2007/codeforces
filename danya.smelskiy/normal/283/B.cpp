#include <bits/stdc++.h>
using namespace std;

long long n;
short used[200005];
long long dp[200005];
long long a[200005];

void dfs(long long x){
    used[x]=1;
    if (a[x]+x>n) {
        dp[x]=a[x];
        used[x]=2;
        return;
    }
    long long z=a[x]+x;
    long long y=a[x];
    y+=a[z];
    z-=a[z];
    if (z<=0) {
        dp[x]=y;
        used[x]=2;
        return;
    }
    if (z==1) {
        dp[x]=-1;
        used[x]=2;
        return;
    }
    if (used[z]==1) {
        dp[x]=-1;
        used[x]=2;
        return;
    } else if (used[z]==2) {
        if (dp[z]!=-1) dp[x]=y+dp[z];
        else dp[x]=-1;
        used[x]=2;
        return;
    } else {
        dfs(z);
        if (dp[z]==-1) dp[x]=-1;
        else dp[x]=y+dp[z];
        used[x]=2;
        return;
    }
}
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (long long i=2;i<=n;++i)
        cin>>a[i];
    for (long long i=2;i<=n;++i)
        if (used[i]==false) dfs(i);
    for (long long i=1;i<n;++i) {
        long long ans=i;
        long long pos=1+i;
        ans+=a[pos];
        pos-=a[pos];
        if (pos<1) cout<<ans<<'\n';
        else if (pos==1) cout<<"-1"<<'\n';
        else {
            if (dp[pos]==-1) cout<<"-1"<<'\n';
            else cout<<dp[pos]+ans<<'\n';
        }
    }
}