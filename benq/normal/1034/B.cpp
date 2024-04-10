#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}

template<int SZ> struct Dinic {
    struct Edge {
        int v;
        ll flow, cap;
        int rev;
    };
 
    vector<Edge> adj[SZ]; 
     
    void addEdge(int u, int v, ll cap) {
        Edge a{v, 0, cap, sz(adj[v])};
        Edge b{u, 0, 0, sz(adj[u])};
        adj[u].pb(a), adj[v].pb(b); 
    } 
     
    int level[SZ], st[SZ];
    
    bool bfs(int s, int t) {
        F0R(i,SZ) level[i] = -1, st[i] = 0;
        level[s] = 0;  
      
        queue<int> q; q.push(s);
        while (sz(q)) {
            int u = q.front(); q.pop();
            for (auto e: adj[u]) 
                if (level[e.v] < 0 && e.flow < e.cap) {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
        }
     
        return level[t] >= 0;
    }
      
    ll sendFlow(int s, int t, ll flow) {
        if (s == t) return flow;
      
        for (  ; st[s] < sz(adj[s]); st[s] ++) {
            Edge &e = adj[s][st[s]]; 
                                          
            if (level[e.v] != level[s]+1 || e.flow == e.cap) continue;
            ll temp_flow = sendFlow(e.v, t, min(flow, e.cap - e.flow));

            if (temp_flow > 0) {
                e.flow += temp_flow;
                adj[e.v][e.rev].flow -= temp_flow;
                return temp_flow;
            }
        }
      
        return 0;
    }
     
    ll maxFlow(int s, int t) {
        if (s == t) return -1;
        ll total = 0;  
        while (bfs(s, t))  while (ll flow = sendFlow(s, t, INT_MAX)) total += flow;
        return total;
    } 
};


int solve(int n, int m) {
    Dinic<402> D = Dinic<402>();
    F0R(i,n) F0R(j,m) {
        int t = m*i+j+1;
        if ((i+j)&1) {
            D.addEdge(0,t,1);
            for (int x = -3; x <= 3; ++x)
                for (int y = -3; y <= 3; ++y) {
                    int X = x+i, Y = y+j;
                    if (abs(x)+abs(y) != 3) continue;
                    if (!(0 <= X && X < n && 0 <= Y && Y < m)) continue;
                    //cout << i << ' ' << j << ' ' << X << ' ' << Y << "\n";
                    D.addEdge(t,m*X+Y+1,1);
                }
        } else D.addEdge(t,401,1);
    }
    //cout << "\n";
    return 2*D.maxFlow(0,401);
}

ll nor (ll x) { return 2*(x/2); }

int main() {
    io();
    /*cout << solve(4,3) << " " << solve(3,4) << "\n";
    exit(0);*/
    /*FOR(i,1,21) {
        FOR(j,1,21) {
            int t = solve(i,j);
            if (i*j-1 <= t) cout << "A " << t << "\t";
            else cout << "B " << t << "\t";
        }
        cout << "\n";
    }*/
    ll m,n; cin >> m >> n;
    ll area = m*n;
    if (m > n) swap(m,n);
    if (m == 1) {
        cout << nor(n/3)+nor((n+1)/3)+nor((n+2)/3);
    } else if (m == 2) {
        if (n == 2) {
            cout << 0;
        } else if (n == 3) {
            cout << 4;
        } else if (n == 7) {
            cout << 12;
        } else cout << nor(area);
    } else {
        cout << nor(area);
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/