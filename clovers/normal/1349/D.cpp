#include<bits/stdc++.h>
using namespace std;
const int N=300005;
const int MOD=998244353;
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
int mul(int x,int y){return 1ll*x*y%MOD;}
int qpow(int x,int y){
    int ret=1;
    while(y){
        if(y&1) ret=mul(ret,x);
        x=mul(x,x);
        y>>=1;
    }
    return ret;
}
int n,a[N],S=0,b[N],dp[N],inv[N];
int main(){
    inv[1]=1;
    for(int i=2;i<N;i++) inv[i]=mul(MOD-MOD/i,inv[MOD%i]);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),S+=a[i];
    b[0]=n-1;
    for(int i=1;i<S;i++){
        int tmp=mul(add(mul(i,b[i-1]),S),n-1);
        b[i]=mul(tmp,qpow(S-i,MOD-2));
    }
    dp[S]=0;
    for(int i=S-1;i>=0;i--) dp[i]=add(dp[i+1],b[i]);
    int ans=0;
    for(int i=1;i<=n;i++) ans=add(ans,dp[a[i]]);
    ans=sub(ans,mul(dp[0],n-1));
    printf("%d\n",mul(ans,qpow(n,MOD-2)));
    return 0;
}