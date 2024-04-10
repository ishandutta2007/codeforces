#include <bits/stdc++.h>
#include <bits/extc++.h>

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
#define mp make_pair
//#define inf 2000000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=200005;
//i_am_noob
template <int mod>
struct Modint{
    int val;
    Modint(int _val=0){val=(_val%mod+mod)%mod;}
    operator int() const {return (*this).val;}
    Modint operator +(const Modint& o) const {return val+o.val>=mod?Modint(val+o.val-mod):Modint(val+o.val);}
    Modint operator -() const {return val?Modint(mod-val):*this;}
    Modint operator -(const Modint& o) const {return val-o.val<0?Modint(val-o.val+mod):Modint(val-o.val);}
    Modint operator *(const Modint& o) const {return Modint(val*o.val%mod);}
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
    bool operator ==(const Modint& o) const {return val==o.val;}
};
#define modint Modint<MOD>

int n,m,e[maxn][2],ans=inf,k;

template<int maxn>
struct graph{
    vector<pii> adj[maxn];
    std::priority_queue<pii,vector<pii>,greater<pii>> pq;
    bool vis[maxn];
    int dist[maxn];
    void add_edge(int u, int v, int w){adj[u].pb({v,w});}
    void dijkstra(int s){
        memset(vis,0,sizeof(vis));
        pq.push({0,s});
        rep(maxn) dist[i]=inf;
        int u,d;
        while(!pq.empty()){
            u=pq.top().second,d=pq.top().first;
            pq.pop();
            if(vis[u]) continue;
            vis[u]=true;
            dist[u]=d;
            for(auto p: adj[u]) pq.push({dist[u]+p.second,p.first});
        }
    }
};
graph<maxn*19> g1;
graph<maxn*2> g2;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    rep(m) cin >> e[i][0] >> e[i][1];
    rep(m) e[i][0]--,e[i][1]--;
    rep(m) rep1(j,19){
        if(j&1) g1.add_edge(j*n+e[i][1],j*n+e[i][0],1);
        else g1.add_edge(j*n+e[i][0],j*n+e[i][1],1);
    }
    rep(n) rep1(j,18) g1.add_edge(j*n+i,(j+1)*n+i,pow2(j));
    g1.dijkstra(0);
    rep(19) ans=min(ans,g1.dist[i*n+n-1]);
    if(ans!=inf){
        print1(modint(ans));
        return 0;
    }
    rep(m) g2.add_edge(e[i][0],e[i][1],1);
    rep(m) g2.add_edge(n+e[i][1],n+e[i][0],1);
    rep(n) g2.add_edge(i,i+n,1000000),g2.add_edge(i+n,i,1000000);
    g2.dijkstra(0);
    k=min(g2.dist[n-1],g2.dist[2*n-1])/1000000;
    ans=modint((modint(2).Pow(k))-modint(1));
    ans=modint(ans+min(g2.dist[n-1],g2.dist[2*n-1])%1000000);
    print1(ans);
    return 0;
}