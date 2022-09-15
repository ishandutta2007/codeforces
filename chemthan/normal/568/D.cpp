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
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#define EPS 1e-9
struct point {
	ld x, y;
	point() {}
	point(ld _x,ld _y) {x = _x; y = _y;}
};
struct line
{
	int idx;
	ld a, b, c;
	line() {idx = 0; a = b = c = 0.0;}
	line(int _idx, ld _a, ld _b, ld _c) {idx = _idx; a = _a; b = _b; c = _c;}
};

bool intersect(line l1, line l2, point& p) {
	if (fabs(l1.a * l2.b - l1.b * l2.a) < EPS) return 0;
	p.x = -(l1.c * l2.b - l1.b * l2.c) / (l1.a * l2.b - l1.b * l2.a);
	p.y = -(l1.c * l2.a - l1.a * l2.c) / (l1.b * l2.a - l1.a * l2.b);
	return 1;
}

const int maxn = 100010;
int n, k;
vector<line> ln;
vii ans;

void solve() {
	scanf("%d%d", &n, &k);
	FOR(i, 0, n) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		ln.push_back(line(i + 1, a, b, c));
	}
	while (k && sz(ln)) {
		if (sz(ln) <= k) {
			FOR(i, 0, sz(ln)) ans.push_back(make_pair(ln[i].idx, -1));
			break;
		}
		bool flag = false;
		FOR(T, 0, 500) {
			int u = 0, v = 0;
			while (u == v) {
				u = rand() % sz(ln);
				v = rand() % sz(ln);
			}
			point p;
			if (!intersect(ln[u], ln[v], p)) continue;
			int cnt = 0;
			FOR(j, 0, sz(ln)) if (fabs(p.x * ln[j].a + p.y * ln[j].b + ln[j].c) < EPS) cnt++;
			if (cnt * k >= sz(ln)) {
				ans.push_back(make_pair(ln[u].idx, ln[v].idx));
				k--;
				FORd(j, sz(ln), 0) if (fabs(p.x * ln[j].a + p.y * ln[j].b + ln[j].c) < EPS) {
					swap(ln[j], ln[sz(ln) - 1]);
					ln.pop_back();
				}
				flag = true;
				break;
			}
		}
		if (!flag) {printf("NO"); return;}
	}
	printf("YES\n%d\n", sz(ans));
	FOR(i, 0, sz(ans)) printf("%d %d\n", ans[i].first, ans[i].second);
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