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

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;

template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

typedef string str;

const int MX = 2e5+5;

int n,m,ka,kb,oc[MX];
vi a, b;
set<int> leaf;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> ka >> kb;
	a.rsz(ka); F0R(i,ka) cin >> a[i];
	b.rsz(kb); F0R(i,kb) cin >> b[i];
	if (sz(a) > m-1 || sz(b) > n-1) {
		cout << "No";
		exit(0);
	}
	cout << "Yes\n";
	while (sz(a) < m-1) a.pb(n);
	while (sz(b) < n-1) b.pb(n+m);
	FOR(i,1,n+m+1) leaf.insert(i);
	trav(t,a) {
		if (!oc[t]) leaf.erase(t);
		oc[t] ++;
	}
	trav(t,b) {
		if (!oc[t]) leaf.erase(t);
		oc[t] ++;
	}
	int ia = 0, ib = 0;
	vpi ed;
	F0R(i,n+m-2) {
		int x = *begin(leaf); leaf.erase(x);
		if (x <= n) {
			assert(ib < sz(b));
			int y = b[ib++]; oc[y] --; ed.pb({x,y});
			if (oc[y] == 0) leaf.insert(y);
		} else {
			assert(ia < sz(a));
			int y = a[ia++]; oc[y] --; ed.pb({x,y});
			if (oc[y] == 0) leaf.insert(y);
		}
	}
	trav(t,leaf) cout << t << " ";
	cout << "\n";
	trav(t,ed) cout << t.f << " " << t.s << "\n";
}