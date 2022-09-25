#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define chkmin(a,b) (a=min(a,b))
#define chkmax(a,b) (a=max(a,b))
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
#define bug(...) 777771449
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=200005,maxm=10000005,maxk=7777714;

//i_am_noob
//#define wiwihorz  
int n,k,par[maxn],maxx[maxn],maxid[maxn];
vector<int> adj[maxn];

void dfs0(int u, int fa){
    par[u]=fa;
    maxid[u]=u;
    for(auto v: adj[u]) if(v!=fa){
        dfs0(v,u);
        if(maxx[v]+1>maxx[u]) maxx[u]=maxx[v]+1,maxid[u]=maxid[v];
    }
}

vector<int> dfs(int u, int fa){
    vector<int> res;
    int v=maxid[u];
    res.pb(maxx[u]+1);
    vector<vector<int>> vec;
    //print(u,v);
    while(v!=u){
        int pv=par[v];
        for(auto vv: adj[pv]) if(vv!=par[pv]&&vv!=v) vec.pb({dfs(vv,pv)});
        v=pv;
    }
    vector<int> vec1;
    vec1.resize(sz(vec));
    priority_queue<pii> pq;
    rep(sz(vec)) pq.push({vec[i].back(),i});
    while(!pq.empty()){
        auto [d,id]=pq.top();
        pq.pop();
        res.pb(res.back()+d);
        vec1[id]=vec[id].back();
        vec[id].pop_back();
        if(sz(vec[id])) pq.push({vec[id].back()-vec1[id],id});
    }
    reverse(all(res));
    return res;
}

void orzck(){
    cin >> n >> k;
    rep(n-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v),adj[v].pb(u);
    }
    dfs0(0,-1);
    vector<int> vec=dfs(0,-1);
    reverse(all(vec));
    //print(sz(vec));
    int ans=-inf;
    rep2(r,1,k+1){
        int maxb;
        if(r-1<sz(vec)) maxb=n-vec[r-1];
        else maxb=0;
        //print(r,maxb);
        if(maxb<=n/2) ans=max(ans,(n-r-maxb)*(r-maxb));
        else ans=max(ans,(n-r-n/2)*(r-n/2));
    }
    print(ans);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    // #ifdef i_am_noob
    // freopen("input1.txt","r",stdin);
    // freopen("output1.txt","w",stdout);
    // freopen("output2.txt","w",stderr);
    // #endif
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