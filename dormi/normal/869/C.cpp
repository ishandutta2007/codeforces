#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=998244353;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll fact[5001];
ll inv[5001];
ll choose(ll a, ll b){
    return fact[a]*inv[b]%mod*inv[a-b]%mod;
}
ll permute(ll a, ll b){
    return fact[a]*inv[a-b]%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    fact[0]=1,inv[0]=1;
    for(int i=1;i<=5000;i++)fact[i]=fact[i-1]*ll(i)%mod,inv[i]=fp(fact[i],mod-2);
    ll a,b,c;
    cin>>a>>b>>c;
    ll ans=0;
    ll total=0;
    for(int i=0;i<=min(b,c);i++){
        total=(total+choose(b,i)*permute(c,i)%mod)%mod;
    }
    for(int i=0;i<=min(b,a);i++){
        for(int j=0;j<=min(a,c);j++){
            ll ways=choose(a,i)*permute(b,i)%mod*choose(a,j)%mod*permute(c,j)%mod;
            ans=(ans+ways*total%mod)%mod;
        }
    }
    printf("%lli\n",ans);
    return 0;
}