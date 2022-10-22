/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<double>;
#define F first
#define S second
//#define X real()
//#define Y imag()
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=2e5+10,LN=19,M=3e2+10,SQ=256,BS=737,inf=1e9;
const ll INF=1e18;
const double pi=acos(-1);
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,greater<pii>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,sz,q[N];
pll p[N];
ll R[N],S[N];
vector<ll> ans;
bool cmp(pll X, pll Y){
    __int128 x=X.F,y=Y.F;
    x*=Y.S;
    y*=X.S;
    return x<=y;
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> S[i] >> R[i];
        p[i]={R[i],i};
    }
    sort(p+1,p+n+1);
    for(ll i=1; i<=n; i++){
        while(sz && (S[q[sz-1]]<S[p[i].S] || (R[q[sz-1]]<R[p[i].S] && S[q[sz-1]]==S[p[i].S]))) sz--;
        if(sz && R[q[sz-1]]==R[p[i].S] && S[q[sz-1]]>S[p[i].S]) continue;
        q[sz++]=p[i].S;
    }
    for(ll i=0; i<sz; i++){
        pll x={(ll)1e12,1},y={0,1};
        for(ll j=0; j<i; j++){
            if(R[q[i]]==R[q[j]] && S[q[i]]==S[q[j]]) continue;
            pll k={(R[q[i]]-R[q[j]])*S[q[i]]*S[q[j]],(S[q[j]]-S[q[i]])*R[q[i]]*R[q[j]]};
            if(cmp(k,x)) x=k;
        }
        for(ll j=i+1; j<sz; j++){
            if(R[q[i]]==R[q[j]] && S[q[i]]==S[q[j]]) continue;
            pll k={(R[q[j]]-R[q[i]])*S[q[i]]*S[q[j]],(S[q[i]]-S[q[j]])*R[q[i]]*R[q[j]]};
            if(cmp(y,k)) y=k;
        }
        if(cmp(y,x)) ans.pb(q[i]);
    }
    sort(ans.begin(),ans.end());
    for(ll i : ans) cout << i << ' ';
    cout << '\n';
    return 0;
}