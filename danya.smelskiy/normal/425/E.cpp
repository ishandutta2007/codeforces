#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

long long dp[2][505][505];
long long f[505];
int n,kk;
inline long long mult(long long a,long long b){
    a*=b;
    if (a>=md) a%=md;
    return a;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>kk;
    f[0]=1;
    for (int i=1;i<=n;++i)
        f[i]=(f[i-1]*2ll)%md;
    dp[0][0][0]=1;
    int x=0,y=1;
    for (int i=1;i<=n;++i) {
        swap(x,y);
        for (int j=0;j<=kk;++j) {
            dp[x][j+1][i]=0;
            for (int k=0;k<i;++k) {
                if (j<kk) {
                    dp[x][j+1][i]=dp[x][j+1][i]+(mult(mult(dp[y][j][k],f[k]),(f[i-k]-1ll)));
                    if (dp[x][j+1][i]>=md) dp[x][j+1][i]-=md;
                }
                dp[x][j][k]=mult(dp[y][j][k],f[k]);
                if (dp[x][j][k]>=md) dp[x][j][k]-=md;
            }
        }
    }
    long long ans=0;
    for (int i=0;i<=n;++i){
        ans+=dp[x][kk][i];
        if (ans>=md) ans-=md;
    }
    cout<<ans;
}