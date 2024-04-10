#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pi> vii;
typedef vector<pl> vll;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#define REMOVE_REDUNDANT
typedef long long T;
const T EPS = 1e-7;
struct PT {
	T x, y;
	PT() {}
	PT(T x, T y) : x(x), y(y) {}
	bool operator < (const PT &rhs) const {return make_pair(y,x) < make_pair(rhs.y,rhs.x);}
	bool operator == (const PT &rhs) const {return make_pair(y,x) == make_pair(rhs.y,rhs.x);}
};
T cross(PT p, PT q) {return p.x * q.y - p.y * q.x;}
T area2(PT a, PT b, PT c) {return cross(a, b) + cross(b, c) + cross(c, a);}
#ifdef REMOVE_REDUNDANT
bool between(const PT &a, const PT &b, const PT &c) {
	return (fabs(area2(a, b, c)) < EPS && (a.x - b.x) * (c.x - b.x) <= 0 && (a.y - b.y) * (c.y - b.y) <= 0);
}
#endif
void ConvexHull(vector<PT> &pts) {
	sort(pts.begin(), pts.end());
	pts.erase(unique(pts.begin(), pts.end()), pts.end());
	vector<PT> up, dn;
	for (int i = 0; i < pts.size(); i++) {
		while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
		while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
		up.push_back(pts[i]);
		dn.push_back(pts[i]);
	}
	pts = dn;
	for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
#ifdef REMOVE_REDUNDANT
	if (pts.size() <= 2) return;
	dn.clear();
	dn.push_back(pts[0]);
	dn.push_back(pts[1]);
	for (int i = 2; i < pts.size(); i++) {
		if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
		dn.push_back(pts[i]);
	}
	if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
		dn[0] = dn.back();
		dn.pop_back();
	}
	pts = dn;
#endif
}
#define Det(a, b, c) ((b.x - a.x) * (c.y - a.y)-(b.y - a.y) * (c.x - a.x))
bool PointInPolygon(vector<PT>& l, PT p){
	int a = 1, b = l.size() - 1, c;
	if (Det(l[0], l[a], l[b]) > 0) swap(a, b);
	if (Det(l[0], l[a], p) >= 0 || Det(l[0], l[b], p) <= 0) return false;
	while(abs(a - b) > 1) {
		c = (a + b) / 2;
		if (Det(l[0], l[c], p) > 0) b = c; else a = c;
	}
	return Det(l[a], l[b], p) < 0;
}

const int maxn = 100010;
int n, m;
int x, y;
int a[maxn];
int b[maxn];
vector<PT> pts, tmp;

void solve() {
	scanf("%d%d", &n, &m);
	scanf("%d%d", &x, &y);
	FOR(i, 0, n) scanf("%d%d", a + i, b + i);
	FOR(i, 0, m) {int c, d; scanf("%d%d", &c, &d); pts.push_back(PT(c, d));}
	ConvexHull(pts);
	int u = 0, v = 0;
	FOR(i, 0, sz(pts)) {
		if (pts[i].x > pts[u].x) u = i;
		if (pts[i].y > pts[v].y) v = i;
	}
	tmp.push_back(PT(0, 0));
	tmp.push_back(PT(pts[u].x, 0));
	FOR(i, u, v + 1) tmp.push_back(pts[i]);
	tmp.push_back(PT(0, pts[v].y));
	FOR(i, 0, n) if (!PointInPolygon(tmp, PT(a[i], b[i]))) {printf("Max"); return;}
	printf("Min");
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}