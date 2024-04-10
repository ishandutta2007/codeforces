#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50,mod=1e9+7;
int n,m,y[N],a[N],b[N],J[N],I[N],ans;
int power(int x,int y){
    int z=1;
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
    return z;
}
int main(){
    scanf("%d%d",&n,&m);J[0]=1;
    for(int i=1;i<=m+2;i++)y[i]=(y[i-1]+power(i,m))%mod;
    if(n<=m+2){printf("%d\n",y[n]);return 0;}
    for(int i=1;i<=m+2;i++)J[i]=1ll*J[i-1]*i%mod;
    I[m+2]=power(J[m+2],mod-2);
    for(int i=m+2;i;i--)I[i-1]=1ll*I[i]*i%mod;
    a[0]=b[m+3]=1;
    for(int i=1;i<=m+2;i++)a[i]=1ll*a[i-1]*(n-i)%mod;
    for(int i=m+2;i;i--)b[i]=1ll*b[i+1]*(n-i)%mod;
    for(int i=1,dat;i<=m+2;i++){
        dat=1ll*y[i]*a[i-1]%mod*b[i+1]%mod*I[i-1]%mod*I[m+2-i]%mod;
        (m+2-i)&1?ans-=dat:ans+=dat;ans%=mod;
    }
    printf("%d\n",(ans+mod)%mod);
    return 0;
}