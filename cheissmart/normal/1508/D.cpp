#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 2002;

struct Point {
	int x, y, val;
	Point(int _x = 0, int _y = 0) { x = _x, y = _y; }
	Point operator + (Point p) { return Point(x + p.x, y + p.y); }
	Point operator - (Point p) { return Point(x - p.x, y - p.y); }
	Point operator += (Point p) { return *this = *this + p; }
	Point operator -= (Point p) { return *this = *this - p; }
	ll operator ^ (Point p) { return (ll) x * p.y - (ll) y * p.x; }
};

struct dsu {
	int p[N];
	dsu(int n) {
		iota(p + 1, p + n + 1, 1);
	}
	int find(int u) {
		return p[u] == u ? u : p[u] = find(p[u]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return;
		p[x] = y;
	}
};

int vis[N], a[N];

signed main()
{
	IO_OP;

	int n; cin >> n;

	dsu dsu(n);
	V<pair<int, Point>> v;
	for(int i = 1; i <= n; i++) {
		Point p; cin >> p.x >> p.y >> p.val;
		a[i] = p.val;
		if(p.val != i) v.EB(i, p);
	}

	if(v.empty()) return cout << 0 << '\n', 0;
	for(int i = 1; i < int(v.size()); i++) if(v[i].S.x < v[0].S.x) swap(v[0], v[i]);
	sort(v.begin() + 1, v.end(), [&] (pair<int, Point> a, pair<int, Point> b) {
		Point A = a.S - v[0].S, B = b.S - v[0].S;
		return (A ^ B) > 0;
	});

	for(int i = 1; i <= n; i++) if(!vis[i]) {
		int j = i;
		while(!vis[j]) {
			vis[j] = 1;
			dsu.unite(j, i);
			j = a[j];
		}
	}
	V<pi> ans;

	auto SWAP = [&] (int i, int j) {
		assert(i != j);
		swap(a[i], a[j]);
		ans.EB(i, j);
	};

	for(int i = 1; i < int(v.size()) - 1; i++) {
		if(dsu.find(v[i].F) != dsu.find(v[i + 1].F)) {
			dsu.unite(v[i].F, v[i + 1].F);
			SWAP(v[i].F, v[i + 1].F);
		}
	}
	int u = v[0].F;
	for(int i = 0; i < int(v.size()) - 1; i++)
		SWAP(u, a[u]);

	for(int i = 1; i <= n; i++) assert(a[i] == i);

	cout << ans.size() << '\n';
	for(pi p:ans) cout << p.F << ' ' << p.S << '\n';

}