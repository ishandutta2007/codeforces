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
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=2e5+10,LN=60,M=1e6+10,SQ=700,BS=737,inf=1.05e9,NSQ=N/SQ+3;
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
ll t,n,a[N],dp[N],pd[N],dd[N],f[3][N],ans;
vector<ll> cp,wt[N],tp;
void upd(ll c, ll t, ll x){
    for(; t<N; t+=t&-t) f[c][t]=(f[c][t]+x)%MOD;
}
ll get(ll c, ll t, ll x=0){
    for(; t; t-=t&-t) x=(x+f[c][t])%MOD;
    return x;
}
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n;
        ans=0;
        cp.clear();
        for(ll i=1; i<=n; i++){
            dp[i]=pd[i]=dd[i]=f[0][i]=f[1][i]=0;
            cin >> a[i];
            cp.pb(a[i]);
        }
        sort(cp.begin(),cp.end());
        cp.resize(unique(cp.begin(),cp.end())-cp.begin());
        for(ll i=1; i<=n; i++){
            a[i]=lower_bound(cp.begin(),cp.end(),a[i])-cp.begin()+1;
            wt[a[i]].pb(i);
        }
        for(ll i=1; i<=n; i++){
            dp[i]=(1+get(0,a[i]-1))%MOD;
            pd[i]=(dp[i]+get(1,a[i]-1))%MOD;
            ans=(ans+pd[i])%MOD;
            upd(0,a[i],dp[i]);
            upd(1,a[i],pd[i]);
        }
        for(ll i=n; i; i--){
            if(wt[a[i]].empty()) continue;
            wt[a[i]].pop_back();
            ll k=a[i]-1;
            tp={0};
            while(!wt[k].empty()){
                for(ll j : wt[k]) tp.pb(j);
                wt[k].clear();
                k--;
            }
            dd[i]=1;
            ans=(ans-dp[i]+MOD)%MOD;
            upd(2,a[i],1);
            sort(tp.begin(),tp.end());
            for(ll k=tp.size()-1; k; k--){
                ll i=tp[k];
                dd[i]=(get(2,n)-get(2,a[i])+MOD)%MOD;
                ans=(ans-dp[i]*dd[i]%MOD+MOD)%MOD;
                upd(2,a[i],dd[i]);
            }
            upd(2,a[i],MOD-1);
            for(ll k=tp.size()-1; k; k--){
                ll i=tp[k];
                upd(2,a[i],MOD-dd[i]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}