#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
const int mod=998244353;
long long Fac[300010],Faci[300010];
long long fast_pow(long long x,long long k){
    long long ans=1;
    while(k){
        if(k&1) ans=ans*x%mod;
        x=x*x%mod;k>>=1;
    }return ans;
}
void Init(int N){
    Fac[0]=1;for(int i=1;i<=N;i++) Fac[i]=Fac[i-1]*i%mod;
    Faci[N]=fast_pow(Fac[N],mod-2);
    for(int i=N;i>=1;i--) Faci[i-1]=Faci[i]*i%mod;
}
long long Binom(int x,int y){
    if(x<y||y<0) return 0;
    return Fac[x]*Faci[y]%mod*Faci[x-y]%mod;
}
int n,f[300010],g[300010];
void solve(){
    scanf("%d",&n);
    f[0]=1;f[1]=1;f[2]=2;
    for(int i=3;i<=n;i++) f[i]=(f[i-1]+1ll*f[i-2]*(i-1)%mod)%mod;
    g[0]=1;
    for(int i=2;i<=n;i+=2) g[i]=1ll*g[i-2]*(i-1)%mod;
    long long ans=0,tmp=1;
    for(int i=0;i*4<=n;i++){
        // printf("%d %lld %lld\n",g[i*2],tmp,Binom(n-i*4+i*2,i*2));
        ans=(ans+1ll*f[n-i*4]*g[i*2]%mod*tmp%mod*Binom(n-i*4+i*2,i*2)%mod)%mod;
        tmp=tmp*2%mod;
    }
    printf("%lld\n",ans);
}
int main(){int T;
    scanf("%d",&T);Init(300005);
    while(T--) solve();
    return 0;
}