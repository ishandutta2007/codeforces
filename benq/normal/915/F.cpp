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
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const int MX = 1000001;

int n, a[MX];
vi adj[MX];
ll ans = 0;

template<int SZ> struct DSU {
    int par[SZ];
    ll sz[SZ];
    DSU() {
        F0R(i,SZ) par[i] = sz[i] = 0;
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

void calc() {
    DSU<MX> D;
    
    vector<pii> t; FOR(i,1,n+1) t.pb({a[i],i});
    sort(all(t));
    
    F0R(i,sz(t)) {
        int x = t[i].s;
        // cout << x << "\n";
        D.par[x] = x, D.sz[x] = 1;
        
        for (int j: adj[x]) if (D.par[j] != 0) {
            int J = D.get(j);
            ans -= D.sz[J]*(D.sz[J]-1)/2*a[x];
            // cout << "OOPS " << i << " " << t[i].s << " " << D.sz[J] << "\n";
            D.unite(x,j);
        }
        
        int X = D.get(x);
        ans += D.sz[X]*(D.sz[X]-1)/2*a[x];
        // cout << "HI " << x << " " << a[x] << " " << D.par[1] << " " << D.par[2] << " " << D.sz[X] << " " << ans << "\n";
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	FOR(i,1,n+1) cin >> a[i];
	F0R(i,n-1) {
	    int a,b; cin >> a >> b;
	    adj[a].pb(b), adj[b].pb(a);
	}
	calc();
	FOR(i,1,n+1) a[i] *= -1;
	calc();
	cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!