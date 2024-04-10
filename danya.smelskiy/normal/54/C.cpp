#include <bits/stdc++.h>
using namespace std;

int n;
long double p[1005];
long double dp[1005][1005];
inline long long get(long long r){
    long long res=0;
    long long last=1;
    for (int i=1;i<=19 && last<=r;++i) {
        long long rr=min(last*(long long)2-1ll,r);
        res+=rr-last+1ll;
        last*=(long long)10;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        long long x,y;
        cin>>x>>y;
        long double res=((get(y))-get(x-1));
        p[i]=(res/(long double)(y-x+1));
    }
    dp[0][0]=1;
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=i;++j) {
            dp[i][j]+=dp[i-1][j]*(1.-p[i]);
            if (j) dp[i][j]+=dp[i-1][j-1]*p[i];
        }
    }
    long double ans=0;
    long double k;
    cin>>k;
    for (int i=0;i<=n;++i){
        if (100*i>=n*k) ans+=dp[n][i];
    }
    cout<<fixed<<setprecision(9)<<ans;
}