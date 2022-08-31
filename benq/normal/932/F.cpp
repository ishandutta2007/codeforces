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
const int MX = 400001;

bool Q;
struct Line {
	mutable ll k, m, p; // slope, y-intercept, last optimal x
	bool operator<(const Line& o) const {
		return Q ? p < o.p : k < o.k;
	}
};

struct LineContainer : multiset<Line> { 
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
	    if (b < 0) a *= -1, b *= -1;
	    if (a >= 0) return a/b;
	    return -((-a+b-1)/b);
	}
	
	// updates x->p, determines if y is unneeded
	bool isect(iterator x, iterator y) { 
		if (y == end()) { x->p = inf; return 0; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}
	
	ll query(ll x) { // gives max value
		if (empty()) return 0;
		Q = 1; auto l = *lb({0,0,x}); Q = 0;
		return l.k * x + l.m;
	}
};

int n, a[MX], b[MX];
ll ans[MX];
vi adj[MX];
LineContainer L[MX];

void dfs(int pre, int cur) {
    for (int i: adj[cur]) if (i != pre) {
        dfs(cur,i);
        if (sz(L[cur]) < sz(L[i])) swap(L[cur],L[i]);
        for (auto a: L[i]) L[cur].add(a.k,a.m);
        L[i].clear();
    }
    ans[cur] = -L[cur].query(a[cur]);
    L[cur].add(-b[cur],-ans[cur]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; 
    FOR(i,1,n+1) cin >> a[i];
    FOR(i,1,n+1) cin >> b[i];
    F0R(i,n-1) {
        int x,y; cin >> x >> y;
        adj[x].pb(y), adj[y].pb(x);
    }
    dfs(0,1);
    FOR(i,1,n+1) cout << ans[i] << " ";
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)