#include<bits/stdc++.h>
using namespace std;
const int N=300,mod=1e9+7;
int n,k,ans,J[N],I[N],pw1[N*N],pw2[N*N];
int power(int x,int y){
    int ret=1;
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)ret=1ll*ret*x%mod;
    return ret;
}
int C(int n,int m){return 1ll*J[n]*I[m]%mod*I[n-m]%mod;}
int main(){
    scanf("%d%d",&n,&k);J[0]=pw1[0]=pw2[0]=1;
    for(int i=1;i<=n;i++)J[i]=1ll*J[i-1]*i%mod;
    I[n]=power(J[n],mod-2);
    for(int i=n;i;i--)I[i-1]=1ll*I[i]*i%mod;
    for(int i=1;i<=n*n;i++)pw1[i]=1ll*pw1[i-1]*(k-1)%mod,pw2[i]=1ll*pw2[i-1]*k%mod;
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++){
        int op=(i+j)&1?-1:1,num=(i+j)*n-i*j;
        ans=(ans+1ll*op*C(n,i)*C(n,j)%mod*power(k-1,num)%mod*power(k,n*n-num))%mod;
    }
    printf("%d\n",(ans+mod)%mod);
    return 0;
}