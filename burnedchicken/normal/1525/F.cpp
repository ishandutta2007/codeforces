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
const int maxn=105;

//i_am_noob
//#define wiwihorz  
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
    void reset(){
        rep(maxn) adj[i].clear();
        edges.clear();
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
int n,m,k,t,x[maxn],y[maxn],dp[maxn][maxn],dp2[maxn][maxn],val[maxn];
vector<pii> e;
vector<int> res,vec[maxn];
bool alive[maxn];

void orzck(){
    cin >> n >> m >> k;
    rep(m){
        int u,v;
        cin >> u >> v;
        e.pb({u,n+v});
    }
    rep(k) cin >> x[i] >> y[i];
    graph<maxn> g;
    rep2(i,1,n+1) g.add_edge(0,i,1),alive[i]=1;
    rep2(i,n+1,2*n+1) g.add_edge(i,maxn-1,1),alive[i]=1;
    for(auto& [u,v]: e) g.add_edge(u,v,1);
    t=g.dinic(0,maxn-1);
    rep1(ii,t){
        int x,y;
        for(auto& j: g.edges) if(j.from!=0&&j.to!=maxn-1&&j.cur==1){
            x=j.from,y=j.to;
            break;
        }
        bug(x,y);
        g.reset();
        alive[x]=0;
        rep2(i,1,n+1) if(alive[i]) g.add_edge(0,i,1);
        rep2(i,n+1,2*n+1) if(alive[i]) g.add_edge(i,maxn-1,1);
        for(auto& [u,v]: e) g.add_edge(u,v,1);
        int tmp=g.dinic(0,maxn-1);
        bug(tmp);
        if(tmp<t-ii){
            if(x<=n) res.pb(x);
            else res.pb(-(x-n));
            continue;
        }
        g.reset();
        alive[x]=1;
        alive[y]=0;
        rep2(i,1,n+1) if(alive[i]) g.add_edge(0,i,1);
        rep2(i,n+1,2*n+1) if(alive[i]) g.add_edge(i,maxn-1,1);
        for(auto& [u,v]: e) g.add_edge(u,v,1);
        g.dinic(0,maxn-1);
        if(y<=n) res.pb(y);
        else res.pb(-(y-n));
    }
    bug(t,sz(res));
    rep(k+1) rep1(j,n+1){
        dp[i][j]=inf;
        if(i-j>=n-t) continue;
        if(i==0){
            if(j==0) dp[i][j]=0;
            else dp[i][j]=inf;
            continue;
        }
        rep1(ii,j+1) if(dp[i-1][ii]+min(x[i-1],y[i-1]*(j-ii))<dp[i][j]){
            dp[i][j]=dp[i-1][ii]+min(x[i-1],y[i-1]*(j-ii));
            dp2[i][j]=j-ii;
        }
    }
    int tot;
    rep(n+1) if(dp[k][i]!=inf){
        tot=i;
        bug(i);
        break;
    }
    print(tot+k);
    rep3(i,k,1){
        val[i]=dp2[i][tot];
        tot-=val[i];
        bug(val[i]);
    }
    int cnt=0;
    rep(k){
        bug(val[i+1]);
        rep1(j,val[i+1]) print0(res[cnt]),cnt++;
        print0(0);
    }
    cout << "\n";
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