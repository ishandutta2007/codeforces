#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
//#define int ll
#define ull unsigned ll
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
const int MOD=Mod;
const int maxn=10005;
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
graph<10105> g;
int n,b,m,cur[5];
pii a[maxn];

void hhhhauraorz(){
    cin >> n >> b >> m;
    rep(m) cin >> a[i].first >> a[i].second;
    sort(a,a+m);
    a[m].first=b,a[m].second=n;
    m++;
    if(a[0].second>a[0].first){
        print("unfair");
        return;
    }
    rep(m-1) if(a[i+1].second<a[i].second||a[i].second+a[i+1].first-a[i].first<a[i+1].second){
        print("unfair");
        return;
    }
    rep(m) g.add_edge(0,i+1,i?a[i].second-a[i-1].second:a[i].second);
    rep(m){
        rep1(j,5) g.add_edge(i+1,m+j+1,(a[i].first+4-j)/5-cur[j]);
        rep1(j,5) cur[j]=(a[i].first+4-j)/5;
    }
    rep(5) g.add_edge(m+i+1,m+6,n/5);
    print(g.dinic(0,m+6)==n?"fair":"unfair");
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