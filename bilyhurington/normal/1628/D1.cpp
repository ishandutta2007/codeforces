#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,f[2010][2010];
const int mod=1e9+7;
void solve(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) f[i][j]=0;
    for(int i=1;i<=n;i++){
        f[i][0]=i;f[i][i]=0;
        for(int j=1;j<i;j++){
            f[i][j]=1ll*(f[i-1][j]+f[i-1][j-1])*((mod+1)/2)%mod;
        }
    }
    printf("%lld\n",1ll*k*f[n][n-m]%mod);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}