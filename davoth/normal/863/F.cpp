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
const int N=3e3+10,LN=19,M=1e8+10,SQ=256,B=737,inf=1e9;
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
// All Costs should be positive (to handle neg cost you should add more code)
template<typename F, typename C> // F = flow, C = cost
struct MinCostMaxFlow {
    struct Edge {
        int to;
        F cap;
        C cost;
        int id;
        Edge () : to(), cap(), cost(), id() {}
        Edge (int _to, F _cap, C _cost, int _id) : to(_to), cap(_cap), cost(_cost), id(_id) {}
    };
    int n;
    vector< Edge > E;
    vector< vector<int> > G;
    vector< int > par, use;
    vector< C > dis, pot;

    MinCostMaxFlow(int _n) : n(_n), use(_n, 0), pot(_n, 0){
        G.resize(_n);
        dis.resize(_n);
        par.resize(_n);
    }
    void AddEdge(int u, int v, F cap, C cost, int id = -1){
        G[u].push_back((int) E.size());
        E.push_back({v, cap, cost, id});
        G[v].push_back((int) E.size());
        E.push_back({u, 0, -cost, id});
    }
    pair<F, C> Push(int src, int snk){
        fill(dis.begin(), dis.end(), numeric_limits<C>::max());
        fill(par.begin(), par.end(), -1);
        fill(use.begin(), use.end(), 0);
        priority_queue<pair<C, int>, vector< pair<C, int> >, greater< pair<C, int> > > pq;
        dis[src] = 0; pq.push({dis[src], src});

        int fr;
        while(!pq.empty()){
            fr = pq.top().S; pq.pop();
            if(use[fr]) continue;
            use[fr] = 1;
            for(auto id : G[fr]){
                if(E[id].cap == 0) continue;
                C w = E[id].cost + pot[fr] - pot[E[id].to];
                if(dis[ E[id].to ] > dis[fr] + w){
                    dis[ E[id].to ] = dis[fr] + w;
                    pq.push({dis[ E[id].to ], E[id].to});
                    par[ E[id].to ] = id;
                }
            }
        }

        if(use[snk] == 0) return {0, 0};

        for(int i = 0; i < n; i++) pot[i] += dis[i];
        F mn = numeric_limits<F>::max();
        for(int u = snk; ~par[u]; u = E[par[u] ^ 1].to) mn = min(mn, E[par[u]].cap);
        for(int u = snk; ~par[u]; u = E[par[u] ^ 1].to) E[par[u]].cap -= mn, E[par[u]^1].cap += mn;
        return {mn, pot[snk]};
    }

    pair<F, C> MinCost(int src, int snk){
        pair<F, C> res, tot = {0, 0};
        while((res = Push(src, snk)).F > 0){
            tot.S += res.F * res.S;
            tot.F += res.F;
        }
        return tot;
    }
};
template<typename F, typename C>
using Flow = MinCostMaxFlow<F, C>;
ll n,q,L[N],R[N];
int main(){
    fast_io;
    cin >> n >> q;
    for(ll i=1; i<=n; i++){
        L[i]=1;
        R[i]=n;
    }
    for(ll i=1; i<=q; i++){
        ll t,l,r,v;
        cin >> t >> l >> r >> v;
        for(ll j=l; j<=r; j++){
            if(t==1) L[j]=max(L[j],v);
            else R[j]=min(R[j],v);
        }
    }
    Flow<ll,ll> flow(3*n+2);
    for(ll i=1; i<=n; i++){
        flow.AddEdge(0,i,1,0);
        flow.AddEdge(n*2+i,n*3+1,n,0);
        if(L[i]>R[i]){
            kill("-1\n");
        }
        for(ll j=L[i]; j<=R[i]; j++) flow.AddEdge(i,n+j,1,0);
        for(ll j=1; j<=n; j++){
            flow.AddEdge(n+i,n*2+i,1,2*j-1);
        }
    }
    cout << flow.MinCost(0,3*n+1).S << '\n';
    return 0;
}