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
const int MX = 1000001;

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

int n,k,p[MX];
vi child[MX];

template<int SZ> struct scc {
    vi adj[SZ], radj[SZ], todo, allComp;
    vi compAdj[SZ];
    int N, comp[SZ], dp[SZ];
    bitset<SZ> visit;
    
    void dfs(int v) {
        visit[v] = 1; 
        for (int w: adj[v]) if (!visit[w]) dfs(w);
        todo.pb(v);
    }
    
    void dfs2(int v, int val) {
        comp[v] = val;
        for (int w: radj[v]) if (comp[w] == -1) dfs2(w,val);
    }
    
    void addEdge(int a, int b) { // cout << a << " " << b << "\n"; 
    a--, b--; adj[a].pb(b), radj[b].pb(a); }
    
    void genSCC() {
        F0R(i,N) comp[i] = -1, visit[i] = 0;
        F0R(i,N) if (!visit[i]) dfs(i);
        reverse(all(todo)); // toposort 
        for (int i: todo) if (comp[i] == -1) dfs2(i,i), allComp.pb(i);
        F0R(i,N) for (int j: adj[i]) if (comp[i] != comp[j]) compAdj[comp[i]].pb(comp[j]);
    }
    
    int finish() {
        int ans = 0;
        F0Rd(i,sz(todo)) {
            int bes = 0;
            for (int j: compAdj[todo[i]]) bes = max(bes,dp[j]);
            dp[todo[i]] += bes;
            ans = max(ans,dp[todo[i]]);
        }
        return ans;
    }
};

scc<MX> S;

vi anc;

void dfs(int x) {
    anc.pb(x);
    if (sz(child[x]) == 0) S.addEdge(x,anc[max(sz(anc)-k-1,0)]);
    for (int i: child[x]) dfs(i);
    anc.pop_back();
}

int main() {
    setIO(); re(n,k);
    FOR(i,2,n+1) {
        re(p[i]);
        child[p[i]].pb(i);
        S.addEdge(p[i],i);
    }
    dfs(1);
    S.N = n;
    S.genSCC();
    // cout << S.N << " " << S.allComp << "\n";
    FOR(i,1,n+1) if (sz(child[i]) == 0) {
        S.dp[S.comp[i-1]] ++;
    }
    cout << S.finish();
}
/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/