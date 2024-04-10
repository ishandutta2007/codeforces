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
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
template<int maxn>
struct graph{
    struct edge{
        int from,to,cur,cap;
        edge(int _from, int _to, int _cap):from(_from),to(_to),cur(0),cap(_cap){}
    };
    vector<int> adj[maxn];
    vector<edge> edges;
    int dist[maxn],cur[maxn];
    bool vis[maxn];
    vector<int> route;
    bool flag;
    void add_edge(int u, int v, int w){
        edges.pb(edge(u,v,w));
        adj[u].pb(sz(edges)-1);
        edges.pb(edge(v,u,0));
        adj[v].pb(sz(edges)-1);
    }
    void dfs(int u, int t){
        if(u==t){
            flag=true;
            return;
        }
        for(; cur[u]<sz(adj[u]); cur[u]++){
            auto& e=edges[adj[u][cur[u]]];
            if(e.cur==e.cap||dist[e.to]!=dist[u]+1) continue;
            dfs(e.to,t);
            if(flag){
                route.pb(adj[u][cur[u]]);
                return;
            }
        }
    }
    int dinic(int s, int t){
        int res=0;
        while(1){
            queue<int> q;
            q.push(s);
            rep(maxn) dist[i]=inf;
            dist[s]=0;
            while(!q.empty()){
                int u=q.front();
                for(auto i: adj[u]){
                    int v=edges[i].to;
                    if(dist[v]!=inf||edges[i].cur==edges[i].cap) continue;
                    q.push(v);
                    dist[v]=dist[u]+1;
                }
                q.pop();
            }
            if(dist[t]==inf) return res;
            rep(maxn) cur[i]=0;
            while(1){
                route.clear();
                flag=false;
                dfs(s,t);
                if(route.empty()) break;
                int minn=inf;
                for(auto i: route) minn=min(minn,edges[i].cap-edges[i].cur);
                for(auto i: route) edges[i].cur+=minn,edges[i^1].cur-=minn;
                res+=minn;
            }
        }
    }
};
const int maxn=505;

//i_am_noob
//#define wiwihorz  
int n,m,res;
bool a[maxn][maxn],b[maxn][maxn],c[maxn][maxn],badr[maxn],badc[maxn];
graph<maxn*2> g;

void orzck(){
    cin >> n >> m;
    rep(n) rep1(j,m){
        char c;
        cin >> c;
        a[i][j]=c=='B';
    }
    rep(n-1) rep1(j,m-1) res+=(b[i][j]=c[i][j]=a[i][j]^a[i][j+1]^a[i+1][j]^a[i+1][j+1]);
    rep3(i,n-1,0) rep3(j,m-1,0) b[i][j]^=b[i+1][j]^b[i][j+1]^b[i+1][j+1];
    rep(n) rep1(j,m) a[i][j]^=b[i][j];
    bug(res);
    rep(n-1) rep1(j,m-1) assert(!(a[i][j]^a[i+1][j]^a[i][j+1]^a[i+1][j+1]));
    bool x=a[0][0];
    rep(n-1) if(a[i][0]^a[i+1][0]) badr[i]=1,x^=1,res++,g.add_edge(0,i+1,1);
    rep(m-1) if(a[0][i]^a[0][i+1]) badc[i]=1,x^=1,res++,g.add_edge(n+1+i,maxn*2-2,1);
    rep(n-1) rep1(j,m-1) if(c[i][j]&&badr[i]&&badc[j]) g.add_edge(i+1,n+1+j,1);
    int k=g.dinic(0,maxn*2-2);
    res-=k;
    if(k&1) x^=1;
    if(x) res++;
    print(res);
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