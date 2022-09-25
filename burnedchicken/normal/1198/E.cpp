#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

#define int long long
#define ull unsigned long long
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
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
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
const int maxn=105;
//i_am_noob
#define y1 y_1
int n,m,x1[maxn],y1[maxn],x2[maxn],y2[maxn],xl,yl,xr,yr;
bool adj[maxn][maxn];
vector<int> vec1,vec2;

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
        edges.pb(edge{v,u,0});
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
graph<2*maxn> g;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    cin >> n >> m;
    rep(m){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        x1[i]--,y1[i]--;
    }
    rep(m) vec1.pb(x1[i]),vec1.pb(x2[i]),vec2.pb(y1[i]),vec2.pb(y2[i]);
    sort(all(vec1)),sort(all(vec2));
    vec1.resize(unique(all(vec1))-vec1.begin());
    vec2.resize(unique(all(vec2))-vec2.begin());
    rep(maxn) rep1(j,maxn) adj[i][j]=false;
    rep(m){
        xl=lower_bound(all(vec1),x1[i])-vec1.begin();
        xr=lower_bound(all(vec1),x2[i])-vec1.begin();
        yl=lower_bound(all(vec2),y1[i])-vec2.begin();
        yr=lower_bound(all(vec2),y2[i])-vec2.begin();
        rep2(j,xl,xr) rep2(k,yl,yr) adj[j][k]=true;
    }
    rep(sz(vec1)-1) g.add_edge(0,i+1,vec1[i+1]-vec1[i]);
    rep(sz(vec2)-1) g.add_edge(i+maxn,2*maxn-1,vec2[i+1]-vec2[i]);
    rep(maxn) rep1(j,maxn) if(adj[i][j]) g.add_edge(i+1,j+maxn,inf);
    print(g.dinic(0,2*maxn-1));
    return 0;
}