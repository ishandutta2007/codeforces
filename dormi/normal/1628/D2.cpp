#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
const ll mod=1e9+7;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll fact[MN],inv[MN];
ll choose(ll a, ll b){
    return fact[a]*inv[b]%mod*inv[a-b]%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    fact[0]=inv[0]=1;
    for(int i=1;i<MN;i++){
        fact[i]=fact[i-1]*ll(i)%mod;
        inv[i]=fp(fact[i],mod-2);
    }
    ll div2=fp(2,mod-2);
    while(t--){
        ll n,m;
        ll k;
        cin>>n>>m>>k;
        ll ans=0;
        for(ll i=1;i<=m;i++){
            pll pos={i,i};
            ll rightupmoves=m-pos.second;
            ll rightmoves=n-pos.first-rightupmoves;
            ll amdivtwo=n-pos.first;
            ll divam=fp(fp(2,amdivtwo),mod-2);
            ll amways=choose(rightupmoves+rightmoves,rightmoves);
            if(i==1){
                ans=(ans+k%mod*amways%mod*divam%mod)%mod;
            }
            else{
                ans=(ans+((i-(i-1)*div2%mod+mod)%mod)*k%mod*amways%mod*divam%mod)%mod;
            }
        }
        printf("%lli\n",ans);
    }
    return 0;
}