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
	ld a, b, c;
	line() {a = b = c = 0.0;}
	line(ld _a, ld _b, ld _c) {a = _a; b = _b; c = _c;}
};
point intersect(line l1, line l2) {
	return point((l1.b * l2.c - l1.c * l2.b) / (l1.a * l2.b - l1.b * l2.a), (l1.c * l2.a - l1.a * l2.c) / (l1.a * l2.b - l1.b * l2.a));
}

bool compare(line l1, line l2) {
	return l1.a * l2.b < l1.b * l2.a;
}

const int maxn = 3010;
int n;
line ln[maxn];

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) {
		cin>>ln[i].a>>ln[i].b>>ln[i].c;
		if (ln[i].a < 0) {ln[i].a *= -1; ln[i].b *= -1; ln[i].c *= -1;}
	}
	sort(ln, ln + n, compare);
	ld tot = 0;
	FOR(i, 0, n) {
		ld xtmp = 0, ytmp = 0;
		FOR(j, 1, n) {
			point p = intersect(ln[i], ln[(i + j) % n]);
			tot += p.x * ytmp - p.y * xtmp;
			xtmp += p.x;
			ytmp += p.y;
		}
	}
	cout<<fixed<<setprecision(9)<<(3.0 * fabs(tot) / n / (n - 1) / (n - 2));
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