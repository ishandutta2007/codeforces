#include<bits/stdc++.h>
using namespace std;
const int N=6005;
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

int down(int n,int k){
    int ret=1;
    for(int i=n;i>=n-k+1;i--) ret=mul(ret,i);
    return ret;
}

int n,m,k,dp[N][N],fac[N];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    fac[0]=1;
    for(int i=1;i<=k;i++) fac[i]=mul(fac[i-1],i);
    for(int i=1;i<=k;i++) dp[i][1]=1;
    for(int i=2;i<=k;i++){
        for(int j=2;j<=i;j++) dp[i][j]=add(dp[i-1][j-1],mul(dp[i-1][j],j));
    }
    int ans=0,p=qpow(m,MOD-2);
    for(int i=1;i<=k;i++){
        ans=add(ans,mul(dp[k][i],mul(down(n,i),qpow(p,i))));
    }
    cout<<ans<<endl;
    return 0;
}