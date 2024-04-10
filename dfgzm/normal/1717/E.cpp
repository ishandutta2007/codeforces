#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100010,mod=1e9+7;
int i,j,k,n,m,T;
int mu[maxn],prime[maxn],is_prime[maxn],cnt;
ll S1[maxn];
ll ksm(ll sum,int num){
    ll ans=1;
    while(num){
        if(num&1)ans=ans*sum%mod;
        sum=sum*sum%mod;
        num>>=1;
    }return ans;
}
ll getsum(ll x){
    return x*(1+x)/2%mod;
}
void init(){
    for(int i=2;i<maxn;i++)is_prime[i]=1;
    mu[1]=1;
    for(int i=2;i<maxn;i++){
        if(is_prime[i])prime[++cnt]=i,mu[i]=-1;
        for(int j=1;j<=cnt && prime[j]*i<maxn;j++){
            is_prime[i*prime[j]]=0;
            if(i%prime[j]==0)break;
            mu[i*prime[j]]=-mu[i];
        }
        // if(i<=100)cerr<<"i="<<i<<' '<<mu[i]<<endl;
    }
    for(i=1;i<maxn;i++)S1[i]=S1[i-1]+1ll*i*i,S1[i]%=mod;
}
ll work1(){
    ll Sum=0;
    for(i=1;i<=n;i++){
        ll s=ksm(__gcd(i,n),mod-2);
        for(j=1;i*j<=n;j++){
            Sum+=(1ll*n*i%mod*s%mod*mu[j]*getsum(n/i/j-1)%mod+mod)%mod;
        }
    }return Sum%mod;
}
ll work2(){
    ll Sum=0;
    for(i=1;i<=n;i++){
        ll s=ksm(__gcd(i,n),mod-2);
        for(j=1;i*j<=n;j++){
            Sum+=(1ll*i*i%mod*s%mod*j%mod*mu[j]%mod*(((n/i/j)*getsum(n/i/j)%mod-S1[n/i/j]+mod)%mod)+mod)%mod;
            Sum%=mod;
            // cerr<<((n/i/j)*getsum(n/i/j)%mod-S1[n/i/j]+mod)%mod<<endl;
            // cerr<<i<<' '<<j<<' '<<Sum<<' '<<(n/i/j)*getsum(n/i/j)%mod<<' '<<S1[n/i/j]<<endl;
        }
    }return Sum%mod;
}
int main(){
    cin>>n;
    init();
    cerr<<work1()<<endl;
    cerr<<work2()<<endl;
    cout<<(work1()-2*work2()+mod+mod)%mod<<endl;
}