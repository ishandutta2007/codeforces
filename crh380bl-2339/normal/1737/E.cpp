#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long f[2000005];
long long sum[2000005];
long long qpow(long long x,int y){
    long long t=1;
    for(;y;y>>=1){
        if(y&1)t=t*x%mod;
        x=x*x%mod;
    }
    return t;
}
const long long inv2=1000000008/2;
long long A[1000005];
void work(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n*2;++i)sum[i]=f[i]=0;
    f[n]=1;
    sum[n]=qpow(inv2,n);
    for(i=n-1;i>=1;--i){
        f[i] = qpow(2LL,i)*(sum[i+1]-sum[i*2]+mod)%mod;
        sum[i]=(sum[i+1]*2-sum[i*2]+mod)%mod;
    }
    //for(i=1;i<=n;++i)printf("%lld ",f[i]);puts("");
    long long ans;
    if(n!=1)A[1]=0;
    else A[1]=1;
    for(i=2;i<=n;++i){
        ans=qpow(inv2, i-(i/2)-1);
        A[i]=ans*f[i]%mod;
    }
    for(i=1;i<=n;++i)printf("%lld\n",A[i]);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}