#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
//#define inf 1010000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=300005;

//i_am_noob
//#define wiwihorz  
int n,m,x,a[maxn],par[maxn];
vector<pii> adj[maxn];
unordered_set<int> good,alive;
vector<int> res;

int Find(int x){return x==par[x]?x:par[x]=Find(par[x]);}

void Union(int u, int v){
    
    if(sz(adj[u])<sz(adj[v])) swap(u,v);
    bug(u,v);
    assert(a[u]+a[v]>=x);
    a[u]+=a[v]-x;
    a[v]=0;
    par[v]=u;
    for(auto& [x,y]: adj[v]) if(Find(x)!=u) adj[u].pb({x,y});
    adj[v].clear();
    alive.erase(v);
    good.erase(v);
}

void orzck(){
    cin >> n >> m >> x;
    rep(n) cin >> a[i];
    rep(n) par[i]=i;
    if(accumulate(a,a+n,0ll)<(n-1)*x){
        print("NO");
        return;
    }
    print("YES");
    rep(m){
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].pb({v,i+1}),adj[v].pb({u,i+1});
    }
    rep(n) if(a[i]>=x) good.insert(i);
    rep(n) alive.insert(i);
    rep(n-1){
        if(!good.empty()){
            int u=*good.begin();
            bug(u);
            while(sz(adj[u])&&Find(adj[u].back().first)==u) adj[u].pop_back();
            adj[u].back().first=Find(adj[u].back().first);
            res.pb(adj[u].back().second);
            assert(sz(adj[u]));
            int v=adj[u].back().first;
            Union(u,v);
            if(a[u]>=x) good.insert(u);
            if(a[v]>=x) good.insert(v);
            if(a[u]<x) good.erase(u);
            if(a[v]<x) good.erase(v);
        }
        else{
            int u=*alive.begin();
            bug(u);
            while(sz(adj[u])&&Find(adj[u].back().first)==u) adj[u].pop_back();
            adj[u].back().first=Find(adj[u].back().first);
            res.pb(adj[u].back().second);
            int v=adj[u].back().first;
            Union(u,v);
            if(alive.count(u)&&a[u]>=x) good.insert(u);
            if(alive.count(v)&&a[v]>=x) good.insert(v);
        }
        bug(good),bug(alive),bug(res);
    }
    for(auto i: res) print(i);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    return 0;
}