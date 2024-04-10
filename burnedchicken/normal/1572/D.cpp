#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")

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
const int MOD=Mod;
template <int mod>
struct Modint{
    int val;
    Modint(int _val=0){val=_val%mod;if(val<0) val+=mod;}
    Modint operator +(const Modint& o) const {
        Modint res;
        res.val=val+o.val;
        if(res.val>=mod) res.val-=mod;
        return res;
    }
    Modint operator +(const int& o) const {return Modint(val+o);}
    Modint operator -() const {
        Modint res;
        res.val=-val;
        if(res.val<0) res.val+=mod;
        return res;
    }
    Modint operator -(const Modint& o) const {
        Modint res;
        res.val=val-o.val;
        if(res.val<0) res.val+=mod;
        return res;
    }
    Modint operator -(const int& o) const {return Modint(val-o);}
    Modint operator *(const Modint& o) const {return Modint(val*o.val);}
    Modint operator *(const int& o) const {return Modint(val*(o%mod));}
    Modint operator +=(const Modint& o){*this=(*this)+o;return *this;}
    Modint operator -=(const Modint& o){*this=(*this)-o;return *this;}
    Modint operator *=(const Modint& o){*this=(*this)*o;return *this;}
    Modint Pow(int b) const {
        Modint tmp(val),ret(1);
        while(b){
            if(b&1) ret*=tmp;
            b>>=1;tmp*=tmp;
        }
        return ret;
    }
    Modint Pow(const Modint& a, int b) const {return a.Pow(b);}
    inline Modint inv() const {return (*this).Pow(mod-2);}
    Modint operator /(const Modint& o) const {return *this*o.inv();}
    Modint operator /(const int& o) const {return *this*Modint(o).inv();}
    bool operator ==(const Modint& o) const {return val==o.val;}
};
template<int mod>
ostream& operator << (ostream& o, Modint<mod> x){return o << x.val;}
template<int mod>
Modint<mod> operator +(const int& x, const Modint<mod>& y){return Modint<mod>(x+y.val);}
template<int mod>
Modint<mod> operator -(const int& x, const Modint<mod>& y){return Modint<mod>(x-y.val);}
template<int mod>
Modint<mod> operator *(const int& x, const Modint<mod>& y){return Modint<mod>(x%mod*y.val);}
#define modint Modint<MOD>
vector<modint> inv,fac,invfac;
void init_comb(int N){
    inv.resize(N),fac.resize(N),invfac.resize(N);
    inv[1]=1,fac[0]=1,invfac[0]=1;
    rep2(i,2,N) inv[i]=inv[MOD%i]*(MOD-MOD/i);
    rep2(i,1,N) fac[i]=fac[i-1]*i;
    rep2(i,1,N) invfac[i]=invfac[i-1]*inv[i];
}
inline modint C(int n, int m){return m>n||m<0?modint(0):fac[n]*invfac[m]*invfac[n-m];}
inline modint H(int n, int m){return C(n+m-1,n);}

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

template<int maxn>
struct mincostflow{
    struct Edge{
        int to,cap,rev,cost;
        Edge(){}
        Edge(int _to, int _cap, int _rev, int _cost):to(_to),cap(_cap),rev(_rev),cost(_cost){}
    };
    vector<Edge> G[maxn];
    void add_edge(int from, int to, int cap, int cost){
        G[from].pb(Edge(to,cap,sz(G[to]),cost));
        G[to].pb(Edge(from,0,sz(G[from])-1,-cost));
    }
    int n,s,t;
    void init(int _n, int _s, int _t){
        n=_n,s=_s,t=_t;
        rep(n+1) G[i].clear();
    }
    int par[maxn],par_id[maxn],dis[maxn];
    bool in_que[maxn];
    pii flow(int s, int t, int lim){
        int flow=0,cost=0;
        while(1){
            if(flow==lim) break;
            rep(maxn) dis[i]=inf;
            rep(maxn) in_que[i]=false;
            dis[s]=0;
            queue<int> que;
            que.push(s);
            while(!que.empty()){
                int tmp=que.front();que.pop();
                in_que[tmp]=false;
                rep1(eid,sz(G[tmp])){
                    Edge e=G[tmp][eid];
                    if(e.cap>0&&dis[e.to]>dis[tmp]+e.cost){
                        dis[e.to]=dis[tmp]+e.cost;
                        par[e.to]=tmp;
                        par_id[e.to]=eid;
                        if(!in_que[e.to]){
                            in_que[e.to]=true;
                            que.push(e.to);
                        }
                    }
                }
            }
            if(dis[t]==inf) break;
            int mn_flow=inf;
            for(int i=t; i!=s; i=par[i]){
                mn_flow=min(mn_flow,G[par[i]][par_id[i]].cap);
            }
            mn_flow=min(mn_flow,lim-flow);
            flow+=mn_flow,cost+=mn_flow*dis[t];
            for(int i=t; i!=s; i=par[i]){
                G[par[i]][par_id[i]].cap-=mn_flow;
                G[i][G[par[i]][par_id[i]].rev].cap+=mn_flow;
            }
        }
        return make_pair(flow,cost);
    }
};

const int maxn=pow2(20)+5,maxm=32,maxk=7777714;

//i_am_noob
//#define wiwihorz  
const int magic=800*49,S=magic+25,T=magic+26;
int n,k,a[maxn];
graph<magic+49> g1;
mincostflow<magic+49> g2;
bool vis[maxn],vis2[maxn];
int id1[maxn],id2[maxn];

void orzck(){
    cin >> n >> k;
    rep(pow2(n)) cin >> a[i];
    vector<array<signed,3>> vec;
    rep(pow2(n)) if(__builtin_popcount(i)%2==0) rep1(j,n) vec.pb({a[i]+a[i^pow2(j)],i,i^pow2(j)});
    if(sz(vec)>magic/2) nth_element(vec.begin(),vec.begin()+magic/2,vec.end(),greater<>());
    while(sz(vec)>magic/2) vec.pop_back();
    sort(all(vec),greater<>());
    int cur_max=0,cur_id=0;
    rep(maxn) id1[i]=id2[i]=-1;
    vector<int> vals;
    int de=0;
    for(auto& arr: vec){
        if(id1[arr[1]]==-1) id1[arr[1]]=cur_id++,g1.add_edge(S,id1[arr[1]],1),vals.pb(arr[1]);
        if(id1[arr[2]]==-1) id1[arr[2]]=cur_id++,g1.add_edge(id1[arr[2]],T,1),vals.pb(arr[2]);
        de++;
        g1.add_edge(id1[arr[1]],id1[arr[2]],1);
        cur_max+=g1.dinic(S,T);
        if(cur_max>=k*2) break;
    }
    bug(de);
    memset(vis,0,sizeof vis);
    for(auto& e: g1.edges) if(e.from!=S&&e.to!=T&&e.cap==1&&e.cur==1) vis[vals[e.from]]=vis[vals[e.to]]=1,de--;
    bug(de);
    cur_id=0;
    rep(pow2(n)) if(__builtin_popcount(i)%2==0) rep1(j,n) if(vis[i]||vis[i^pow2(j)]){
        if(id2[i]==-1) id2[i]=cur_id++,g2.add_edge(S,id2[i],1,0);
        if(id2[i^pow2(j)]==-1) id2[i^pow2(j)]=cur_id++,g2.add_edge(id2[i^pow2(j)],T,1,0);
        g2.add_edge(id2[i],id2[i^pow2(j)],1,-(a[i]+a[i^pow2(j)]));
    }
    bug(cur_id);
    pii res=g2.flow(S,T,k);
    print(-res.second);
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
    ld start=clock();
    while(t--) orzck();
    bug((clock()-start)/CLOCKS_PER_SEC);
    return 0;
}