#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
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
const int MX = 200001;

template<int SZ> struct DSU {
    int par[SZ], sz[SZ];
    DSU() {
        F0R(i,SZ) par[i] = i, sz[i] = 1;
    }
    
    int get(int x) { // path compression
    	if (par[x] != x) par[x] = get(par[x]);
    	return par[x];
    }
    
    bool unite(int x, int y) { // union-by-rank
    	x = get(x), y = get(y);
    	if (x == y) return 0;
    	if (sz[x] < sz[y]) swap(x,y);
    	sz[x] += sz[y], par[y] = x;
    	return 1;
    }
};

DSU<MX> D;
int n,S[MX];
vpi adj[MX];
ll flo[MX];
bool done[MX];

void dfs(int cur, int pre) {
    done[cur] = 1;
    for (auto a: adj[cur]) if (a.f != pre) {
        dfs(a.f,cur);
        if (a.s > 0) {
            flo[a.s] += S[a.f];
            S[cur] += S[a.f];
        } else {
            flo[abs(a.s)] -= S[a.f];
            S[cur] += S[a.f];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; FOR(i,1,n+1) cin >> S[i];
    int m; cin >> m;
    FOR(i,1,m+1) {
        int a,b; cin >> a >> b;
        if (D.unite(a,b)) {
            adj[a].pb({b,i}), adj[b].pb({a,-i});
        }
    }
    FOR(i,1,n+1) if (!done[i]) {
        dfs(i,0);
        if (S[i] != 0) {
            cout << "Impossible";
            exit(0);
        }
    }
    cout << "Possible\n";
    FOR(i,1,m+1) cout << flo[i] << "\n";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS