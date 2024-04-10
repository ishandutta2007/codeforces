#include <bits/stdc++.h>
using namespace std;



long long n,m,p;
long long x,y;
long long d[200005];
long long dp[200005],dp1[200005];
long long a[200005];
inline long long ff(long long aa,long long b){
    return dp[aa]+a[b]*(b-aa)-d[b]+d[aa];
}
inline long double pnt(long long aa,long long b){
    return (long double)(dp[b]+d[b]-dp[aa]-d[aa])/(long double)(b-aa);
}
int q[200005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>p;
    for (int i=2;i<=n;++i){
        cin>>x;
        d[i]=d[i-1]+x;
    }
    for (int i=1;i<=m;++i)
        dp[i]=1e18;
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        y-=d[x];
        a[i]=y;
    }
    sort(a+1,a+m+1);
    for (int i=1;i<=m;++i) {
        d[i]=d[i-1]+a[i];
    }
    for (int i=1;i<=p;++i) {
        int l=1,r=1; q[1]=0;
        for (int j=1;j<=m;++j){
            while (l<r && ff(q[l],j)>ff(q[l+1],j)) ++l;
            dp1[j]=ff(q[l],j);
            while (l<r && pnt(q[r-1],q[r])>pnt(q[r],j)) --r;
            q[++r]=j;
        }
        for (int j=1;j<=m;++j)
            dp[j]=min(dp[j],dp1[j]);
    }
    cout<<dp[m];
}