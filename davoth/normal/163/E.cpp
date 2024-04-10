#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
using namespace std;
using ll = /*long long*/ int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=20,M=1e5+10,SQ=250,inf=1e9;
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
ll n,k,Q[N],L,R,C[N][26],F[N],a[M*2],q,ts,t,st[N],fn[N],f[N],en[M*2],P[N];
string s[M*2];
vector<ll> adj[N];
pll qu[M];
void AddTrie(ll i){
    int v=0;
    for (char ch : s[i]){
        if (!C[v][ch-'a']){
            C[v][ch-'a']=++ts,P[ts]=v;
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
    cin >> q >> n;
    for(ll i=1; i<=n; i++){
        cin >> s[i];
        AddTrie(i);
        a[i]=1;
    }
    for(ll i=1; i<=q; i++){
        char c;
        cin >> c;
        if(c=='+'){
            ll x;
            cin >> x;
            qu[i]={1,x};
        }else if(c=='-'){
            ll x;
            cin >> x;
            qu[i]={0,x};
        }else{
            cin >> s[n+(++k)];
            qu[i]={2,n+k};
        }
    }
    BuildAho();
    dfs(0);
    for(ll i=1; i<=n; i++){
        upd(st[en[i]],1);
        upd(fn[en[i]]+1,-1);
    }
    for(ll i=1; i<=q; i++){
        auto [t,x]=qu[i];
        if(qu[i].F<2){
            upd(st[en[x]],t-a[x]);
            upd(fn[en[x]]+1,a[x]-t);
            a[x]=t;
        }else{
            ll ans=0,v=0;
            for(char ch : s[x]){
                v=C[v][ch-'a'];
                ans+=get(st[v]);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}