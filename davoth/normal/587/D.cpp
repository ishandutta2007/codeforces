#include <bits/stdc++.h>
using namespace std;
using ll = int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e6+10,LN=20,SQ=550,M=5e4+10;
//const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<pll,ll>, null_type,less<pair<pll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,col[N],c,m,s[N],g,ed[M];
vector<ll> out[N],in[N];
vector<ll> topol,ans,f;
vector<pair<pll,ll>> adj[M];
map<ll,ll> mp[M];
bool fl[N],d;
void add_edge(ll v, ll u){
    out[v].push_back(u);
    in[u].push_back(v);
}
void add_sat(ll x, ll y){
    add_edge(x^1,y);
    add_edge(y^1,x);
}
void dfs(ll v){
    fl[v]=1;
    for(ll u : out[v]) if(!fl[u]) dfs(u);
    topol.push_back(v);
}
void sfd(ll v){
    fl[v]=1;
    col[v]=c;
    for(ll u : in[v]) if(!fl[u]) sfd(u);
}
void DFS(ll v){
    for(ll u : out[v]){
        if(s[u]==0) d=1;
        if(s[u]==-1) s[u]=1,DFS(u);
    }
}
void SFD(ll v){
    for(ll u : in[v]){
        if(s[u]==1) d=1;
        if(s[u]==-1) s[u]=0,SFD(u);
    }
}
void build(ll z, ll v, ll l, ll r){
    if(r-l<=1){
        f[v]=g;
        add_sat(g*2+1,adj[z][l].F.S*2+1);
        g++;
        return;
    }
    ll md=(l+r)/2;
    build(z,v*2,l,md);
    build(z,v*2+1,md,r);
    f[v]=g;
    add_sat(g*2+1,f[v*2]*2);
    add_sat(g*2+1,f[v*2+1]*2);
    g++;
}
void con(ll v, ll l, ll r, ll tl, ll tr, ll x){
    if(tl>=tr) return;
    if(tl==l && tr==r){
        add_sat(x^1,f[v]*2);
        return;
    }
    ll md=(l+r)/2;
    con(v*2,l,md,tl,min(tr,md),x);
    con(v*2+1,md,r,max(md,tl),tr,x);
}
bool check(ll t){
    d=0;
    memset(s,-1,sizeof s);
    for(ll i=0; i<m; i++) if(ed[i]>t) s[i*2]=0,s[i*2+1]=1;
    for(ll i=0; i<g*2; i++){
        if(s[i]==1) DFS(i);
        else if(s[i]==0) SFD(i);
        if(s[i]!=-1 && s[i^1]==s[i]) d=1;
    }
    if(d) return 0;
    return 1;
}
int main(){
    fast_io;
    cin >> n >> m;
    g=m;
    for(ll i=0; i<m; i++){
        ll v,u,k,t;
        cin >> v >> u >> k >> t;
        adj[v].push_back({{u,i},k});
        adj[u].push_back({{v,i},k});
        ed[i]=t;
    }
    for(ll i=1; i<=n; i++){
        ll k=adj[i].size();
        if(k==0) continue;
        f.reserve(k*8);
        build(i,1,0,k);
        ll h=0,j,i1=m,i2=m;
        for(ll o=0; o<k; o++){
            auto p=adj[i][o];
            mp[i][p.S]++;
            if(mp[i][p.S]==3) return cout << "No\n", 0;
            if(mp[i][p.S]==2) h++,j=p.S;
            con(1,0,k,0,o,p.F.S*2);
            con(1,0,k,o+1,k,p.F.S*2);
        }
        if(h>1) return cout << "No\n", 0;
        if(h==1){
            for(auto p : adj[i]){
                if(p.S==j && i1==m) i1=p.F.S;
                else if(p.S==j) i2=p.F.S;
            }
            add_sat(i1*2,i2*2);
        }
        f.clear();
    }
    for(ll i=0; i<2*g; i++) if(!fl[i]) dfs(i);
    reverse(topol.begin(),topol.end());
    memset(fl,0,sizeof fl);
    for(ll i : topol) if(!fl[i]) sfd(i),c++;
    for(ll i=0; i<g; i++){
        if(col[2*i]==col[2*i+1]) return cout << i << '\n', 0;
    }
    //cout << "SALAM" << endl;
    ll l=-1,r=1e9+2;
    while(r-l>1){
        ll md=(l+r)/2;
        if(check(md)) r=md;
        else l=md;
    }
    check(r);
    for(ll i=0; i<g*2; i++){
        if(s[i]==-1) s[i]=col[i]>col[i^1];
    }
    for(ll i=0; i<m; i++) if(s[i*2]) ans.push_back(i+1);
    cout << "Yes\n" << r << ' ' << ans.size() << '\n';
    for(ll i : ans) cout << i << ' ';
    cout << '\n';
    return 0;
}