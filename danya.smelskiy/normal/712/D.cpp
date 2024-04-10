#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int a,b,k,t;

long long dp[2][3000005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>k>>t;
    int x=0,y=1;
    dp[x][k*t]=1;
    for (int i=1;i<=t;++i) {
        swap(x,y);
        for (int j=0;j<=k*t*2;++j){
            dp[x][j]=0;
            dp[y][j]=(dp[y][j]+(j ? dp[y][j-1] : 0ll))%md;
        }
        for (int j=0;j<=k*t*2;++j) {
            int l=max(0,j-k);
            int r=min(k*t*2,j+k);
            long long res=dp[y][r]-(l ? dp[y][l-1] : 0ll);
            if (res<0) res+=md;
            dp[x][j]=res;
        }
    }
    dp[y][0]=dp[x][0];
    for (int j=1;j<=k*t*2;++j){
        dp[y][j]=dp[x][j];
        dp[x][j]=(dp[x][j]+dp[x][j-1])%md;
    }
    long long ans=0;
    for (int j=0;j<=k*t*2;++j) {
        int aa=a+j-b;
        aa=min(aa,k*t*2+1);
        if (aa>0) ans=(ans+(dp[y][j]*dp[x][aa-1]))%md;
    }
    cout<<ans;
}