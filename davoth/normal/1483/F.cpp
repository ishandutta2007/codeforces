#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0);
const int N=1e6+10,LN=24,M=1e7+10,SQ=500,B=737,inf=1e9;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
string S[N];
ll n,T,V,L,R,C[N][26],Q[N],F[N],G[N],f[N],st[N],fn[N],cnt[N],D[N],P[N],ans;
vector<ll> adj[N];
vector<pll> vec;
void upd(ll t, ll x){
    while(t<N) f[t]+=x,t+=t&-t;
}
ll get(ll t, ll x=0){
    while(t) x+=f[t],t-=t&-t;
    return x;
}
void dfs(ll v){
    st[v]=++T;
    for(ll u : adj[v]) dfs(u);
    fn[v]=T;
}
void AddTrie(ll i){
    ll v=0;
    for(char c : S[i]){
        if(!C[v][c-'a']){
            C[v][c-'a']=++V;
            P[V]=v;
        }
        v=C[v][c-'a'];
    }
    D[i]=v;
    G[v]=i;
}
void BuildAho(){
    for(ll i=0; i<26; i++) if(C[0][i]) Q[R++]=C[0][i];
    while(L<R){
        ll v=Q[L++];
        adj[F[v]].pb(v);
        if(!G[v]) G[v]=G[F[v]];
        for(ll i=0; i<26; i++){
            if(C[v][i]){
                F[C[v][i]]=C[F[v]][i];
                Q[R++]=C[v][i];
            }else{
                C[v][i]=C[F[v]][i];
            }
        }
    }
}
void Solve(ll i){
    ll v=0,sz=0;
    for(char c : S[i]){
        sz++;
        v=C[v][c-'a'];
        ll u=G[v];
        if(sz==S[i].size()) u=G[F[v]];
        if(u){
            ll k=sz-S[u].size();
            while(!vec.empty() && vec.back().S>=k){
                cnt[vec.back().F]--;
                vec.pop_back();
            }
            vec.pb({u,k});
            cnt[u]++;
        }
        upd(st[v],1);
    }
    for(auto [u,k] : vec){
        if(cnt[u]==get(fn[D[u]])-get(st[D[u]]-1)){
            ans++;
        }
        cnt[u]--;
    }
    vec.clear();
    while(v){
        upd(st[v],-1);
        v=P[v];
    }
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> S[i];
        AddTrie(i);
    }
    BuildAho();
    dfs(0);
    for(ll i=1; i<=n; i++) Solve(i);
    cout << ans << '\n';
    return 0;
}