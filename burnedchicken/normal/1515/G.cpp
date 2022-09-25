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
const int maxn=200005;

//i_am_noob
//#define wiwihorz  
int n,m,q,val[maxn],k;
vector<int> radj[maxn];
vector<pii> adj[maxn];
vector<array<int,3>> vec[maxn];
bool res[maxn],vis[maxn],vis2[maxn];
vector<int> ord,vec1;

void rdfs(int u){
    vis[u]=1;
    for(auto v: radj[u]) if(!vis[v]) rdfs(v);
    ord.pb(u);
}

void dfs(int u, int cur){
    bug(u,cur);
    vis[u]=1;
    vec1.pb(u);
    val[u]=cur;
    for(auto& [v,w]: adj[u]) if(!vis2[v]){
        if(!vis[v]) dfs(v,cur+w);
        else k=__gcd(k,cur+w-val[v]),bug(cur+w-val[v]);
    }
}

void orzck(){
    cin >> n >> m;
    rep(m){
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        adj[u].pb({v,w});
        radj[v].pb(u);
    }
    cin >> q;
    rep(q){
        int u,x,k;
        cin >> u >> x >> k;
        u--;
        vec[u].pb({k,x?k-x:x,i});
    }
    rep(n) if(!vis[i]) rdfs(i);
    reverse(all(ord));
    memset(vis,0,sizeof vis);
    for(auto i: ord){
        if(!vis[i]){
            k=0;
            vec1.clear();
            dfs(i,0);
            for(auto j: vec1) vis2[j]=1;
            bug(k);
            for(auto j: vec1) for(auto a: vec[j]){
                if(!a[1]) res[a[2]]=1;
                else if(!k) res[a[2]]=0;
                else res[a[2]]=!(a[1]%__gcd(k,a[0]));
            }
        }
    }
    rep(q) print(res[i]?"YES":"NO");
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