#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
#define ook order_of_key
#define fbo find_by_order
 
using namespace std;
 
template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
	
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a : x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
 
#define f first
#define s second
#define all(x) begin(x), end(x)
#define rsz resize
#define ub upper_bound
#define lb lower_bound

const int MX = 2e5+5;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
 
template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

int n;
vi d;
vi adj[MX];
vpi ed;

void bad() {
	cout << -1;
	exit(0);
}

void ae(int a, int b) {
	if (!a || !b) bad();
	d[a] --, d[b] --; ed.pb({a,b});
}

void addCyc(vi v) {
	assert(sz(v) >= 2); 
	F0R(i,sz(v)) {
		if (i < sz(v)-1) ae(v[i],v[i+1]);
		else if (sz(v) > 2) ae(v[i],v[0]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; d.rsz(n+1); FOR(i,1,n+1) cin >> d[i];
	int lef = n;
	while(1) {
		if (lef == 2) {
			vi rem; FOR(i,1,n+1) if (d[i] == 1) rem.pb(i);
			if (sz(rem) != 2) bad();
			addCyc({rem[0],rem[1]}); break;
		}
		int v = 0; FOR(i,1,n+1) if (d[i] == 1) v = i;
		if (v) {
			int w = 0; 
			FOR(i,1,n+1) if (d[i] > 1 && (d[i]&1)) {
				if (d[i] > d[w]) w = i;
			}
			if (w) { addCyc({v,w}); lef --; continue; }
			FOR(i,1,n+1) if (d[i] > 1) {
				if (d[i] > d[w]) w = i;
			}
			if (!w) bad();
			addCyc({v,w}); lef --; continue;
		}
		vi two;
		FOR(i,1,n+1) if (d[i] == 2) two.pb(i);
		if (sz(two) < 2) bad();
		if (sz(two) == lef) {
			addCyc(two);
			break;
		}
		int w = 0; FOR(i,1,n+1) if (d[i] > d[w]) w = i;
		addCyc({two[0],two[1],w}); lef -= 2;
	}
	FOR(i,1,n+1) assert(d[i] == 0);
	cout << sz(ed) << "\n";
	trav(t,ed) {
		cout << "2 " << t.f << " " << t.s << "\n";
	}
}