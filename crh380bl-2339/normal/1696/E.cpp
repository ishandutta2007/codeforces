#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 200005
int a[N];
int fac[N+N],_fac[N+N];
int qpow(int x,int y){
    int t=1;
    for(;y;y>>=1){
        if(y&1)t=1LL*t*x%mod;
        x=1LL*x*x%mod;
    }
    return t;
}
int C(int n,int m){
    if(n<m||m<0)return 0;
    return 1LL*fac[n]*_fac[m]%mod*_fac[n-m]%mod;
}
int main(){
    int n,i,j,ans=0;
    scanf("%d",&n);
    for(i=0;i<=n;++i)scanf("%d",&a[i]);
    fac[0]=1;
    for(i=1;i<N+N;++i)fac[i]=1LL*fac[i-1]*i%mod;
    _fac[N+N-1]=qpow(fac[N+N-1],mod-2);
    for(i=N+N-2;i>=0;--i)_fac[i]=1LL*(i+1)*_fac[i+1]%mod;
    for(i=0;i<=n;++i){
        ans=(ans+C(i+a[i],i+1))%mod;
    }
    printf("%d\n",ans);
    return 0;
}