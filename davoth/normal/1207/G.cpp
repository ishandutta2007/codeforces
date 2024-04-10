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
using point=complex<ld>;
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
#define killshayan kill("done!\n")
const int N=4e5+10,LN=19,M=1e8+10,SQ=256,B=737,inf=1e9;
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
ll n,m,C[N][26],L,R,Q[N],F[N],T,st[N],fn[N],f[N],ans[N],ed[N];
string S[N];
vector<pair<ll,char>> G[N];
vector<ll> adj[N],qu[N];
void AddTrie(int i){
    int v=0;
    for(char c : S[i]){
        if(!C[v][c-'a']) C[v][c-'a']=++T;
        v=C[v][c-'a'];
    }
    ed[i]=v;
}
void BuildAho(){
    for(int i=0; i<26; i++) if(C[0][i]) Q[R++]=C[0][i];
    while(L<R){
        int v=Q[L++];
        adj[F[v]].pb(v);
        for(int i=0; i<26; i++){
            if(!C[v][i]) C[v][i]=C[F[v]][i];
            else{
                F[C[v][i]]=C[F[v]][i];
                Q[R++]=C[v][i];
            }
        }
    }
}
void dfs(ll v){
    st[v]=++T;
    for(ll u : adj[v]) dfs(u);
    fn[v]=T;
}
void upd(ll t, ll x){
    while(t<N) f[t]+=x,t+=t&-t;
}
ll get(ll t, ll x=0){
    while(t) x+=f[t],t-=t&-t;
    return x;
}
void sfd(ll v, ll V){
    upd(st[V],1);
    for(ll i : qu[v]){
        ans[i]=get(fn[ed[i]])-get(st[ed[i]]-1);
    }
    for(auto [u,c] : G[v]){
        sfd(u,C[V][c-'a']);
    }
    upd(st[V],-1);
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        ll t;
        char c;
        cin >> t;
        if(t==1){
            cin >> c;
            G[0].pb({i,c});
        }else{
            ll x;
            cin >> x >> c;
            G[x].pb({i,c});
        }
    }
    cin >> m;
    for(ll i=1; i<=m; i++){
        ll j;
        cin >> j >> S[i];
        AddTrie(i);
        qu[j].pb(i);
    }
    BuildAho();
    T=0;
    dfs(0);
    sfd(0,0);
    for(ll i=1; i<=m; i++) cout << ans[i] << '\n';
    return 0;
}