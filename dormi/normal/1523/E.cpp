#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=1e9+7;
const int MV=1e6+1;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll fact[MV],inv[MV];
ll choose(ll a, ll b){
    return fact[a]*inv[b]%mod*inv[a-b]%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    fact[0]=inv[0]=1;
    for(int i=1;i<MV;i++){
        fact[i]=fact[i-1]*ll(i)%mod;
        inv[i]=fp(fact[i],mod-2);
    }
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll ans=0;
        ll totways=n-1+1;
        ll failcnt=0;
        for(ll i=2;i<=n;i++){
            totways=totways*(n-i+1)%mod;
            ll usedspace=(i-1)*(k)+1;
            ll ways;//here and succed
            if(usedspace>n){
                ways=0;
            }
            else{
                ll extraspace=n-usedspace;
                ll locations=i+1;
                ways=choose(extraspace+locations-1,locations-1)*fact[i]%mod;
            }
            failcnt=failcnt*(n-i+1)%mod;
            ll waysfail=(totways-ways-failcnt+mod+mod)%mod;
            failcnt=(failcnt+waysfail)%mod;
            ans=(ans+waysfail*fp(totways,mod-2)%mod*i%mod)%mod;
        }
        printf("%lli\n",ans);
    }
    return 0;
}