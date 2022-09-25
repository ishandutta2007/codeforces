#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

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
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=1005;
//i_am_noob
//#define wiwihorz  
int n,x[maxn],y[maxn],cur,match[maxn];
vector<int> adj[maxn],adj1[maxn],adj2[maxn];
vector<vector<int>> vec1,vec2,res1,res2;
map<int,vector<int>> m1,m2;
bool vis[maxn],vis1[maxn],vis2[maxn],matched1[maxn],matched2[maxn];

bool dfs(int u){
    for(auto v: adj[u]){
        if(vis[v]) continue;
        vis[v]=true;
        if(match[v]==-1||dfs(match[v])){
            match[v]=u;
            return true;
        }
    }
    return false;
}

void dfs1(int u, bool b){
    if(!b){
        vis1[u]=true;
        for(auto v: adj1[u]){
            if(vis2[v]) continue;
            dfs1(v,b^1);
        }
    }
    else{
        vis2[u]=true;
        for(auto v: adj2[u]){
            if(vis1[v]) continue;
            dfs1(v,b^1);
        }
    }
}

void hhhhauraorz(){
    cin >> n;
    rep(n) cin >> x[i] >> y[i];
    rep(n) m1[x[i]].pb(y[i]),m2[y[i]].pb(x[i]);
    for(auto& p: m1) sort(all(p.second));
    for(auto& p: m2) sort(all(p.second));
    for(auto& p: m1) rep(sz(p.second)-1){
        vec1.pb({p.first,p.second[i],p.second[i+1]});
    }
    for(auto& p: m2) rep(sz(p.second)-1) vec2.pb({p.first,p.second[i],p.second[i+1]});
    rep(sz(vec2)) match[i]=-1;
    rep(sz(vec1)) rep1(j,sz(vec2)) if(vec2[j][0]>vec1[i][1]&&vec2[j][0]<vec1[i][2]&&vec1[i][0]>vec2[j][1]&&vec1[i][0]<vec2[j][2]) adj[i].pb(j);
    rep(sz(vec1)){
        memset(vis,0,sizeof vis);
        dfs(i);
    }
    rep(sz(vec2)) if(match[i]!=-1) matched1[match[i]]=true;
    rep(sz(vec1)) for(auto j: adj[i]){
        if(match[j]==i) adj2[j].pb(i);
        else adj1[i].pb(j);
    }
    rep(sz(vec1)) if(!matched1[i]) dfs1(i,0);
    cur=0;
    for(auto& p: m1){
        vector<int> tmp;
        tmp.pb(p.second[0]);
        rep(sz(p.second)-1){
            if(!vis1[cur]) tmp.pb(p.second[i]),tmp.pb(p.second[i+1]);
            cur++;
        }
        tmp.pb(p.second.back());
        rep(sz(tmp)/2) res1.pb({p.first,tmp[2*i],p.first,tmp[2*i+1]});
    }
    cur=0;
    for(auto& p: m2){
        vector<int> tmp;
        tmp.pb(p.second[0]);
        rep(sz(p.second)-1){
            if(vis2[cur]) tmp.pb(p.second[i]),tmp.pb(p.second[i+1]);
            cur++;
        }
        tmp.pb(p.second.back());
        rep(sz(tmp)/2) res2.pb({tmp[2*i],p.first,tmp[2*i+1],p.first});
    }
    print(sz(res2));
    for(auto& vec: res2){
        for(auto i: vec) print0(i);
        cout << "\n";
    }
    print(sz(res1));
    for(auto& vec: res1){
        for(auto i: vec) print0(i);
        cout << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) hhhhauraorz(); 
    return 0;
}