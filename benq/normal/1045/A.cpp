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
const int MX = 25000;

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

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    
	// pair
	template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
	    is >> p.f >> p.s;
	    return is;
	}
	template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
	    os << '{' << a.f << ", " << a.s << '}';
	    return os;
	}
	
    // vector
	template<class T> istream& operator>>(istream& is, vector<T>& a) {
	    int sz; is >> sz; a.resize(sz);
	    F0R(i,sz) is >> a[i];
	    return is;
	}
	template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
	    os << "{";
	    F0R(i,sz(a)) {
	        if (i) os << ", ";
	        os << a[i];
	    }
	    os << "}";
	    return os;
	}
}

using namespace io;

Dinic<MX> D;
int N,M, nex = 2, label[MX];
// source = 0, sink = 1

void build(int ind, int L, int R) {
    label[ind] = nex ++;
    if (L == R) {
        D.addEdge(label[ind],1,1);
    } else {
        int M = (L+R)/2;
        build(2*ind,L,M);
        build(2*ind+1,M+1,R);
        D.addEdge(label[ind],label[2*ind],MOD);
        D.addEdge(label[ind],label[2*ind+1],MOD);
    }
}

void addRange(int id, int ind, int L, int R, int lo, int hi) {
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        D.addEdge(id,label[ind],1);
        return;
    }
    int M = (L+R)/2;
    addRange(id,2*ind,L,M,lo,hi);
    addRange(id,2*ind+1,M+1,R,lo,hi);
}

int t[MX], ind[MX];
vi aa[MX], bb[MX];
vi v[MX];
set<int> adj[MX];
int rev[MX];

void build2(int ind, int L, int R) {
    if (L != R) {
        int M = (L+R)/2;
        build2(2*ind,L,M);
        build2(2*ind+1,M+1,R);
        bb[label[ind]] = bb[label[2*ind]];
        bb[label[ind]].insert(bb[label[ind]].end(),all(bb[label[2*ind+1]]));
    } else {
        bb[label[ind]] = {L};
    }
    while (sz(aa[label[ind]]) && sz(bb[label[ind]])) {
        int x = aa[label[ind]].back(), y = bb[label[ind]].back();
        adj[x].insert(y); rev[y] = x;
        aa[label[ind]].pop_back(), bb[label[ind]].pop_back();
    }
}

void finish() {
    cout << D.maxFlow(0,1) << "\n";
    FOR(i,1,N+1) for (auto a: D.adj[ind[i]]) if (a.v != 0 && a.flow) {
        // cout << "AH " << i << " " << a.v << "\n";
        aa[a.v].pb(i);
    }
    build2(1,1,M);
    FOR(i,1,N+1) if (t[i] == 2 && sz(adj[i]) == 1) {
        for (int z: v[i]) if (!adj[i].count(z)) {
            adj[rev[z]].erase(z);
            adj[i].insert(z);
            break;
        }
    }
    FOR(i,1,N+1) for (int j: adj[i]) cout << i << " " << j << "\n";
}

int main() {
    setIO(); re(N,M);
    build(1,1,M);
    FOR(i,1,N+1) {
        cin >> t[i]; ind[i] = nex ++;
        if (t[i] == 0) {
            D.addEdge(0,ind[i],1);
            int K; cin >> K;
            F0R(j,K) {
                int k; cin >> k;
                addRange(ind[i],1,1,M,k,k);
            }
        } else if (t[i] == 1) {
            D.addEdge(0,ind[i],1);
            int L,R; cin >> L >> R;
            addRange(ind[i],1,1,M,L,R);
        } else {
            D.addEdge(0,ind[i],2);
            int a,b,c; cin >> a >> b >> c;
            v[i] = {a,b,c};
            for (int j: v[i]) addRange(ind[i],1,1,M,j,j);
        }
    }
    finish();
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/