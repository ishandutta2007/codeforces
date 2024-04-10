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
const int N=1e5+10,LN=20,M=1e5+10,SQ=350,inf=1e9;
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
ll n,q,ans[N],Q[N],L,R,C[N][26],F[N],en[N],ts,a[N],k,b[N],f[N],g[SQ],ti,st[N],fn[N];
string s[N];
vector<pll> q1[N],q2[N];
vector<ll> adj[N];
vector<pair<pll,ll>> q0[N];
void AddTrie(ll j){
    int v=0;
    for (char ch : s[j]){
        if (!C[v][ch-'a']) C[v][ch-'a']=++ts;
        v=C[v][ch-'a'];
    }
    en[j]=v;
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
void dfs(ll v){
    st[v]=++ti;
    for(ll u : adj[v]) dfs(u);
    fn[v]=ti;
}
void add(ll t, ll x){
    ll c=SQ*(t/SQ+1);
    for(ll i=t; i<c; i++) f[i]+=x;
    for(ll i=t/SQ+1; i*SQ<N; i++) g[i]+=x;
}
ll get(ll t){
    return f[t]+g[t/SQ];
}
int main(){
    fast_io;
    cin >> n >> q;
    for(ll i=1; i<=n; i++){
        cin >> s[i];
        a[i]=s[i].size();
        AddTrie(i);
    }
    BuildAho();
    for(ll i=1; i<=q; i++){
        ll l,r,k;
        cin >> l >> r >> k;
        if(a[k]<=SQ){
            q1[l-1].pb({k,i});
            q2[r].pb({k,i});
        }else{
            q0[k].pb({{l,r},i});
        }
    }
    dfs(0);
    for(ll i=1; i<=n; i++){
        add(st[en[i]],1);
        add(fn[en[i]]+1,-1);
        for(auto [k,j] : q1[i]){
            ll v=0;
            for(char ch : s[k]){
                v=C[v][ch-'a'];
                ans[j]-=get(st[v]);
            }
        }
        for(auto [k,j] : q2[i]){
            ll v=0;
            for(char ch : s[k]){
                v=C[v][ch-'a'];
                ans[j]+=get(st[v]);
            }
        }
    }
    for(ll k=1; k<=n; k++){
        if(a[k]<=SQ) continue;
        vector<ll> q1[n+1],q2[n+1];
        ll pr[ti+1];
        memset(pr,0,sizeof pr);
        ll v=0,cur=0;
        for(char ch : s[k]){
            v=C[v][ch-'a'];
            pr[st[v]]++;
        }
        for(ll i=1; i<=ti; i++) pr[i]+=pr[i-1];
        for(auto [p,j] : q0[k]){
            q1[p.F-1].pb(j);
            q2[p.S].pb(j);
        }
        for(ll i=1; i<=n; i++){
            cur+=pr[fn[en[i]]]-pr[st[en[i]]-1];
            for(ll j : q1[i]) ans[j]-=cur;
            for(ll j : q2[i]) ans[j]+=cur;
        }
    }
    for(ll i=1; i<=q; i++) cout << ans[i] << '\n';
    return 0;
}