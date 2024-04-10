#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vi=vector<ll>;
using vvi=vector<vi>;
using P=pair<ll,ll>;
using PP=tuple<ll,ll,ll>;
using vp=vector<P>;
using vvp=vector<vp>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define REP(i,k,n) for(ll i=(ll)(k);i<(ll)(n);i++)
#define all(a) a.begin(),a.end()
#define rsort(a) {sort(all(a));reverse(all(a));}
#define dupli(a) {sort(all(a));a.erase(unique(all(a)),a.end());}
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define fi first
#define se second
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
const ll inf=1001001001001001001;
const int mod=1000000007;
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
ll modpow(ll a,ll b){
    a%=mod;
    if(b==0)return 1ll;
    if(b&1)return a*modpow(a,b-1)%mod;
    ll k=modpow(a,b/2);
    return k*k%mod;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,l=20;cin>>n;
    vi v(1<<l);
    rep(i,n){
        ll a;cin>>a;v[a^((1<<l)-1)]++;
    }
    vvi dp(1<<l,vi(l+1));
    rep(i,1<<l){
        dp[i][0]=v[i];
        rep(j,l){
            dp[i][j+1]+=dp[i][j];
            if(i>>j&1)dp[i][j+1]+=dp[i&~(1<<j)][j];
        }
    }
    ll ans=0;
    rep(i,1<<l){
        ll c=__builtin_popcount(i);
        if(c&1)ans-=modpow(2,dp[i][l]);
        else ans+=modpow(2,dp[i][l]);
        ans%=mod;
    }
    ans+=mod;
    out(ans%mod);
}