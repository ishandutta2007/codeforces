#include<bits/stdc++.h>
using namespace std;
const int N=51;
const int M=51;
const int MOD=998244353;
int mul(int x,int y){return 1ll*x*y%MOD;}
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
int qpow(int x,int y){
    int ret=1;
    while(y){
        if(y&1) ret=mul(ret,x);
        x=mul(x,x);
        y>>=1;
    }
    return ret;
}
int n,m,a[N],w[N];
int dp[M][N][N],cnt1=0,cnt2=0,sum1=0,sum2=0;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++) if(a[i]==0) cnt2++,sum2+=w[i]; else cnt1++,sum1+=w[i];
    for(int i=1;i<=n;i++){
        dp[0][i][0]=w[i];
    }
    for(int i=0;i<m;i++){
        for(int j=1;j<=n;j++){
            for(int ad=0;ad<=i;ad++){
                int sb=i-ad,now=sum1+sum2+ad-sb;
                if(sb>sum2) continue;
                int now1=sum1+ad,now2=sum2-sb;
                int inv=qpow(now,MOD-2);
                if(a[j]){
                    now1=sub(now1,dp[i][j][ad]);
                    dp[i+1][j][ad+1]=add(dp[i+1][j][ad+1],mul(dp[i][j][ad]+1,mul(dp[i][j][ad],inv)));
                    dp[i+1][j][ad+1]=add(dp[i+1][j][ad+1],mul(dp[i][j][ad],mul(now1,inv)));
                    dp[i+1][j][ad]=add(dp[i+1][j][ad],mul(dp[i][j][ad],mul(now2,inv)));
                }
                else{
                    now2=sub(now2,dp[i][j][ad]);
                    dp[i+1][j][ad]=add(dp[i+1][j][ad],mul(dp[i][j][ad]-1,mul(dp[i][j][ad],inv)));
                    dp[i+1][j][ad]=add(dp[i+1][j][ad],mul(dp[i][j][ad],mul(now2,inv)));
                    dp[i+1][j][ad+1]=add(dp[i+1][j][ad+1],mul(dp[i][j][ad],mul(now1,inv)));
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        int ans=0;
        for(int ad=0;ad<=m;ad++) ans=add(ans,dp[m][i][ad]);
        printf("%d\n",ans);
    }
    return 0;
}