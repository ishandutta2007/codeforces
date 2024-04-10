#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;const int mod=1e9+7;
long long fast_pow(long long x,long long k){
    long long ans=1;
    while(k){
        if(k&1) ans=ans*x%mod;
        x=x*x%mod;k>>=1;
    }return ans;
}
const int MAXN=1000000;
long long Fac[MAXN+10],Faci[MAXN+10];
void Pre_Fac(){
    Fac[0]=1;for(int i=1;i<=MAXN;i++) Fac[i]=Fac[i-1]*i%mod;
    Faci[MAXN]=fast_pow(Fac[MAXN],mod-2);
    for(int i=MAXN;i>=1;i--) Faci[i-1]=Faci[i]*i%mod;
}
long long Binom(int n,int m){
    if(m<0||n<m) return 0;
    return Fac[n]*Faci[m]%mod*Faci[n-m]%mod;
}
void solve(){
    scanf("%d %d %d",&n,&m,&k);
    long long ans=0;m=n-m;
    if(!m) ans=fast_pow(2,n)*n%mod;
    else{
        for(int i=1;i<n;i++){
            ans=(ans+fast_pow(2,i)*i%mod*Binom(n-i-1,m-1))%mod;
        }
    }
    printf("%lld\n",ans*fast_pow(fast_pow(2,n),mod-2)%mod*k%mod);
}
int main(){
    scanf("%d",&T);Pre_Fac();
    while(T--) solve();
    return 0;
}