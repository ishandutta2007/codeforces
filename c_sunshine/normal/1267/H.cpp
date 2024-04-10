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

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
 
template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }
 
typedef string str;
 
const int MX = 2e5+5;
const int MOD = 1e9+7;

int t,n;
set<int> oc[25];
vi p;
int f[8501];

int one(int l, int r, int i) {
	auto it = oc[i].lb(l);
	if (it != end(oc[i]) && *it <= r) {
		if (next(it) != end(oc[i]) && *next(it) <= r) return MOD;
		return *it;
	}
	return -1;
}

bool ok(int x) {
	vector<bool> use(25);
	int l = 1, r = n;
	while(1) {
		bool done = 0;
		ROF(i,1,25) if (!use[i]) {
			int ind = one(l,r,i);
			if (ind == MOD) continue;
			if (ind == -1) {
				use[i] = 1;
				continue;
			}
			// cout << "OOPS " << i << " " << ind << "\n";
			if (ind == x) return 1;
			if (ind > x) r = ind-1;
			else l = ind+1;
			use[i] = 1;
			done = 1;
			break;
		}
		if (!done) return 0;
	}
}

bool fail;
int dumb;

void ad(int x) {
	vi posi;
	for (int i = 1; ; ++i) {
		if (i > 24) {
			if (!sz(posi)) {
				fail = 1;
				return;
			}
			oc[posi.back()].insert(x); f[x] = posi.back();
			break;
		}
		oc[i].insert(x);
		if (!ok(x)) {
			oc[i].erase(x);
		} else {
			if (rand()%200 <= dumb) {
				posi.pb(i); oc[i].erase(x);
				continue;
			}
			f[x] = i; break;
		}
	}
}

void solve() {
	cin >> n; p.rsz(n); F0R(i,n) cin >> p[i];
	// cout << "OK " << n << "\n";
	// cout << "HA\n"; exit(0);
	fail = 1;
	for (dumb = 0; dumb < 150; dumb ++) {
		FOR(i,1,25) oc[i].clear();
		fail = 0; FOR(i,1,n+1) f[i] = 0; 
		trav(t,p) if (!fail) ad(t);
		if (!fail) break;
	}
	if (fail) exit(5);
	FOR(i,1,n+1) cout << f[i] << " ";
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	F0R(i,t) solve();
}