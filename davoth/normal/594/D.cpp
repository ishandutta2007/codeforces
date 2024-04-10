#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=30,SQ=550,M=1e6+10;
const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,a[N],f[N],g[M],q,ans[N];
vector<ll> v[M],u[M],z[M];
vector<pll> y[N];
bool c[M];
void update(ll t, ll x){
    while(t<N){
        f[t]*=x;
        f[t]%=MOD;
        t+=t&-t;
    }
}
ll get(ll t, ll x=1){
    while(t){
        x*=f[t];
        t-=t&-t;
        x%=MOD;
    }
    return x;
}
int main(){
    fast_io;
    cin >> n;
    fill(f,f+N,1);
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    for(ll i=2; i<M; i++){
        if(!c[i]){
            for(ll j=i; j<M; j+=i){
                for(ll k : v[j]) u[i].push_back(k);
                z[j].push_back(i);
                c[j]=1;
            }
        }
    }
    cin >> q;
    for(ll i=0; i<q; i++){
        ll l,r;
        cin >> l >> r;
        y[l].emplace_back(r,i);
    }
    for(ll i=1; i<M; i++){
        if(u[i].empty()) continue;
        sort(u[i].begin(),u[i].end());
        update(u[i][0],(i-1)*pow(i,MOD-2,MOD)%MOD);
        g[i]++;
    }
    for(ll i=1; i<=n; i++) update(i,a[i]);
    for(ll i=1; i<=n; i++){
        for(pll p : y[i]){
            ans[p.S]=get(p.F);
        }
        for(ll t : z[a[i]]){
            update(i,t*pow(t-1,MOD-2,MOD)%MOD);
            if(g[t]==u[t].size()) continue;
            update(u[t][g[t]],(t-1)*pow(t,MOD-2,MOD)%MOD);
            g[t]++;
        }
        update(i,pow(a[i],MOD-2,MOD));
    }
    for(ll i=0; i<q; i++) cout << ans[i] << '\n';
    return 0;
}