#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=20,M=1e5+10,SQ=250,inf=1e9;
const ll INF=1e18;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,Q[N],L,R,C[N][26],F[N],q,ts,t,st[N],fn[N],f[N],en[N],ans[N];
string s[N];
vector<ll> adj[N];
vector<pll> q1[N],q2[N];
void AddTrie(ll i){
    int v=0;
    for (char ch : s[i]){
        if (!C[v][ch-'a']){
            C[v][ch-'a']=++ts;
        }
        v=C[v][ch-'a'];
    }
    en[i]=v;
}
void dfs(ll v){
    st[v]=++t;
    for(ll u : adj[v]) dfs(u);
    fn[v]=t;
}
void upd(ll t, ll x){
    while(t<N) f[t]+=x,t+=t&-t;
}
ll get(ll t, ll x=0){
    while(t) x+=f[t],t-=t&-t;
    return x;
}
void BuildAho(){
    for (int i=0; i<26; i++) if (C[0][i]) Q[R++]=C[0][i];
    while (L<R){
        int v=Q[L++];
        adj[F[v]].pb(v);
        for (int i=0; i<26; i++){
            if (!C[v][i]) C[v][i]=C[F[v]][i];
            else{
                F[C[v][i]]=C[F[v]][i];
                Q[R++]=C[v][i];
            }
        }
    }
}
int main(){
    fast_io;
    cin >> n >> q;
    for(ll i=1; i<=n; i++){
        cin >> s[i];
        AddTrie(i);
    }
    BuildAho();
    dfs(0);
    for(ll i=1; i<=q; i++){
        ll l,r,k;
        cin >> l >> r >> k;
        q1[l-1].pb({k,i});
        q2[r].pb({k,i});
    }
    for(ll i=1; i<=n; i++){
        ll v=0;
        for(char ch : s[i]){
            v=C[v][ch-'a'];
            upd(st[v],1);
        }
        for(auto [k,j] : q1[i]){
            ans[j]-=get(fn[en[k]])-get(st[en[k]]-1);
        }
        for(auto [k,j] : q2[i]){
            ans[j]+=get(fn[en[k]])-get(st[en[k]]-1);
        }
    }
    for(ll i=1; i<=q; i++) cout << ans[i] << '\n';
    return 0;
}