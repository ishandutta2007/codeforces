#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=120000;
const int MOD=1e9+7;
void Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
void Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
void Mul(int &x,int y){x=1ll*x*y%MOD;}
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

int fac[5005],n,k,C[5005],dp[5005][5005];
int main(){
    scanf("%d%d",&n,&k);
    //dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*j   
    dp[1][1]=1;
    for(int i=2;i<=k;i++){
        for(int j=1;j<=i;j++) dp[i][j]=add(dp[i-1][j-1],mul(dp[i-1][j],j));
    }
    C[0]=1; fac[0]=1;
    for(int i=1;i<=k;i++){
        C[i]=mul(C[i-1],mul(n-i+1,qpow(i,MOD-2)));
        fac[i]=mul(fac[i-1],i);
    }
    int ans=0;
    for(int j=1;j<=k;j++){
        if(j<=n) Add(ans,mul(mul(dp[k][j],qpow(2,n-j)),mul(fac[j],C[j])));
    }
    cout<<ans<<endl;
    return 0;
}