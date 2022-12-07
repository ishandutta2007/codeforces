#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define mod 1000000007
int fac[N],ifac[N];
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
    return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
    int n,k,i,ans = 0;
    scanf("%d%d",&n,&k);
    fac[0]=1;
    for(i=1;i<=1000000;++i)fac[i] = 1LL*fac[i-1]*i%mod;
    ifac[1000000] = qpow(fac[1000000], mod-2);
    for(i=999999;i>=0;--i)ifac[i]=1LL*(i+1)*ifac[i+1]%mod;
    if(k==0){
        printf("%d\n",qpow(3,n));
        return 0;
    }
    for(i=1;i<=k;++i){
        int A = 1LL*C(n+1-k, i)*C(k-1,i-1)%mod;
        int B = 1LL*C(n-k, i)*C(k-1, i-1)%mod;
        A = (A-B+mod)%mod;
        if(A){
            ans = (1LL*ans + 1LL*A*qpow(3, n-2*i+1))%mod;
        }
        if(B){
            ans = (1LL*ans + 1LL*B*qpow(3, n-2*i))%mod;
        }
    }
    printf("%d\n",ans);
    return 0;
}