#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
const ll mod=1e9+7;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll fact[2*MN];
ll inv[2*MN];
ll choose(ll a, ll b){
    if(b>a)return 0;
    return fact[a]*inv[b]%mod*inv[a-b]%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    fact[0]=inv[0]=1;
    for(int i=1;i<2*MN;i++){
        fact[i]=fact[i-1]*ll(i)%mod;
        inv[i]=fp(fact[i],mod-2)%mod;
    }
    int a;
    ll ans=0;
    for(int i=0;i<=n;i++){
        cin>>a;
        if(a>0)ans=(ans+choose(i+a,i+1))%mod;
    }
    printf("%lli\n",ans);
    return 0;
}