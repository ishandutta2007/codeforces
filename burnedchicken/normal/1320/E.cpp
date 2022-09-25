#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

//#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define inf 1010000000
//#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
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
int n,u,v,cur,dep[maxn],id[maxn],fa[maxn][18],q,k,m,x,s[maxn];
vector<int> adj[maxn],adj2[maxn],vec,vec1,vec2,vec3;
pii dis[maxn];
bool vis[maxn];

void dfs(int u, int par){
    dep[u]=~par?dep[par]+1:0;
    id[u]=cur++;
    fa[u][0]=par;
    rep2(i,1,18) fa[u][i]=~fa[u][i-1]?fa[fa[u][i-1]][i-1]:-1;
    for(auto v: adj[u]) if(v!=par){
        dfs(v,u);
    }
}

int lca(int u, int v){
    if(dep[u]>dep[v]) swap(u,v);
    rep(18) if((dep[v]-dep[u])&pow2(i)) v=fa[v][i];
    if(u==v) return u;
    rep3(i,17,0) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}

void build(vector<int> vec, vector<int>& vec2){
    if(none_of(all(vec),[](int i){return !i;})) vec.pb(0);
    sort(all(vec),[](int i, int j){return id[i]<id[j];});
    vector<int> sk;
    vec2.clear();
    for(auto u: vec){
        if(sk.empty()){
            sk.pb(u);
            adj2[u].clear();
            vec2.pb(u);
            continue;
        }
        int v=lca(sk.back(),u);
        if(v==sk.back()){
            sk.pb(u);
            adj2[u].clear();
            vec2.pb(u);
            continue;
        }
        while(sz(sk)>=2&&dep[sk[sz(sk)-2]]>=dep[v]){
            adj2[sk.back()].pb(sk[sz(sk)-2]);
            adj2[sk[sz(sk)-2]].pb(sk.back());
            sk.pop_back();
        }
        if(sz(sk)>=1&&sk.back()!=v){
            adj2[v].clear();
            adj2[sk.back()].pb(v);
            adj2[v].pb(sk.back());
            sk.pop_back();
            sk.pb(v);
            vec2.pb(v);
        }
        sk.pb(u);
        adj2[u].clear();
        vec2.pb(u);
    }
    rep(sz(sk)-1){
        adj2[sk[i]].pb(sk[i+1]);
        adj2[sk[i+1]].pb(sk[i]);
    }
}

struct cmp{
    bool operator ()(const pair<pii,int>& i, const pair<pii,int>& j) const {
        return ceiling(i.first.first,s[i.first.second])==ceiling(j.first.first,s[j.first.second])?i.first.second>j.first.second:ceiling(i.first.first,s[i.first.second])>ceiling(j.first.first,s[j.first.second]);
    }
};

priority_queue<pair<pii,int>,vector<pair<pii,int>>,cmp> pq;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    cin >> n;
    rep(n-1){
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v),adj[v].pb(u);
    }
    dfs(0,-1);
    cin >> q;
    while(q--){
        cin >> k >> m;
        vec1.resize(k),vec2.resize(m);
        rep(sz(vec1)){
            cin >> vec1[i] >> s[i];
            vec1[i]--;
        }
        for(auto& i: vec2) cin >> i;
        for(auto& i: vec2) i--;
        vec3.clear();
        for(auto& i: vec1) vec3.pb(i);
        for(auto& i: vec2) vec3.pb(i);
        build(vec3,vec);
        for(auto& i: vec) dis[i]={inf,0},vis[i]=false;
        rep(sz(vec1)) dis[vec1[i]]={0,i};
        rep(sz(vec1)) pq.push(make_pair(dis[vec1[i]],vec1[i]));
        while(!pq.empty()){
            u=pq.top().second;
            pii p=pq.top().first;
            pq.pop();
            if(vis[u]) continue;
            vis[u]=true;
            dis[u]=p;
            for(auto v: adj2[u]) pq.push({{p.first+abs(dep[u]-dep[v]),p.second},v});
        }
        for(auto& i: vec2) print0(dis[i].second+1);
        cout << "\n";
    }
    return 0;
}