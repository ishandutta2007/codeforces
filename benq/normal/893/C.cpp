#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

const int MOD = 1000000007;

int n,m;

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

DSU<100001> D;
int c[100001];
map<int,int> t;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	FOR(i,1,n+1) cin >> c[i];
	F0R(i,m) {
	    int a,b; cin >> a >> b;
	    D.unite(a,b);
	}
	FOR(i,1,n+1) {
	    D.par[i] = D.get(i);
	    if (t.count(D.par[i])) t[D.par[i]] = min(t[D.par[i]],c[i]);
	    else t[D.par[i]] = c[i];
	}
	ll ans = 0;
	for (auto a: t) ans += a.s;
	cout << ans;
}

// read!
// ll vs. int!