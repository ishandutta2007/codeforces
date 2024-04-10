#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<ld>;
#define F first
#define S second
//#define X real()
//#define Y imag()
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!\n")
const int N=4e3+10,LN=19,M=1e8+10,SQ=256,B=737,inf=1e9;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
template<typename T>
struct Dinic {
    struct Edge {
        int to;
        T cap;

        Edge () : to(), cap() {}
        Edge (int _to, T _cap) : to(_to), cap(_cap) {}
    };
    int n;
    vector< Edge > E;
    vector< vector<int> > G;
    vector< int > idx, dis, Q;

    Dinic(int _n) : n(_n) {
        G.resize(_n);
        idx.resize(_n);
        dis.resize(_n);
        Q.resize(_n);
    }
    void AddEdge(int u, int v, T cap){
        G[u].push_back((int) E.size());
        E.push_back({v, cap});

        G[v].push_back((int) E.size());
        E.push_back({u, 0});
    }
    bool BFS(int src, int snk){
        fill(dis.begin(), dis.end(), -1);

        dis[src] = 0;
        int L = 0, R = 1;
        Q[0] = src;

        int fr;
        while(L < R){
            fr = Q[L ++];
            for(auto id : G[fr]){
                if(E[id].cap > 0 && dis[ E[id].to ] == -1){
                    dis[ E[id].to ] = dis[fr] + 1;
                    Q[R ++] = E[id].to;
                }
            }
        }
        return dis[snk] != -1;
    }

    T DFS(int u, int snk, T flow){
        if(u == snk || flow == 0) return flow;

        T res = 0, cur;
        for(auto &id = idx[u]; id < (int) G[u].size(); id ++){
            Edge &ed = E[ G[u][id] ];

            if(dis[ ed.to ] != dis[u] + 1) continue;

            cur = DFS(ed.to, snk, min(flow, ed.cap));
            flow -= cur; res += cur;

            ed.cap -= cur;
            E[ G[u][id] ^ 1 ].cap += cur;
            if(flow == 0) break;
        }
        return res;
    }

    T MaxFlow(int src, int snk){
        T res = 0;
        while( BFS(src, snk) ){
            fill(idx.begin(), idx.end(), 0);
            res += DFS(src, snk, numeric_limits<T>::max());
        }
        return res;
    }
    T MinCut(int src, int snk){
        return MaxFlow(src, snk);
    }
};
template<typename T>
using Flow = Dinic<T>;
ll n1,n2,n,m,d[N],D;
vector<pll> ed;
int main(){
    fast_io;
    cin >> n1 >> n2 >> m;
    for(ll i=0; i<m; i++){
        ll v,u;
        cin >> v >> u;
        ed.pb({v,u+n1});
        d[v]++;
        d[u+n1]++;
    }
    n=n1+n2;
    D=d[n];
    for(ll i=1; i<n; i++) D=min(D,d[i]);
    for(ll i=0; i<=D; i++){
        Flow<ll> flow(n+2);
        for(auto [v,u] : ed){
            flow.AddEdge(v,u,1);
        }
        for(ll j=1; j<=n1; j++) flow.AddEdge(0,j,d[j]-i);
        for(ll j=n1+1; j<=n; j++) flow.AddEdge(j,n+1,d[j]-i);
        cout << m-flow.MaxFlow(0,n+1) << ' ';
        for(ll i=0; i<m*2; i+=2) if(flow.E[i].cap) cout << i/2+1 << ' ';
        cout << '\n';
    }
    return 0;
}