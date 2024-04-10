#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

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
const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

pi ans = {MOD,MOD};


int N,m,h,u[MX];
vi adj[MX];

template<int SZ> struct scc {
    vi adj[SZ], radj[SZ],  todo, allComp;
    int comp[SZ], sz[SZ], out[SZ];
    bitset<SZ> visit;
    
    void dfs(int v) {
    	visit[v] = 1; 
    	for (int w: adj[v]) if (!visit[w]) dfs(w);
    	todo.pb(v);
    }
    
    void dfs2(int v, int val) {
    	comp[v] = val;
    	for (int w: radj[v]) if (!comp[w]) dfs2(w,val);
    }
    
    void addEdge(int a, int b) {
		adj[a].pb(b), radj[b].pb(a);
    }
    
    void genSCC() {
        FOR(i,1,N+1) comp[i] = visit[i] = 0;
    	FOR(i,1,N+1) if (!visit[i]) dfs(i);
    	reverse(all(todo)); // toposort 
    	for (int i: todo) if (!comp[i]) {
    	    dfs2(i,i);
    	    allComp.pb(i);
    	}
    	FOR(i,1,N+1) {
    	    sz[comp[i]] ++;
    	    for (int j: adj[i]) if (comp[j] != comp[i]) out[comp[i]] ++;
    	}
    	FOR(i,1,N+1) if (sz[i] > 0 && out[i] == 0) {
    	    ans = min(ans,{sz[i],i});
    	}
    }
};

scc<MX> S;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> m >> h;
    FOR(i,1,N+1) cin >> u[i];
    F0R(i,m) {
        int a,b; cin >> a >> b;
        if ((u[a]+1)%h == u[b]) S.addEdge(a,b);
        if ((u[b]+1)%h == u[a]) S.addEdge(b,a);
    }
    
    S.genSCC();
    cout << ans.f << "\n";
    FOR(i,1,N+1) if (S.comp[i] == ans.s) cout << i << " ";
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)