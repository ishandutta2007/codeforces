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

const int maxn = 1010;
int n, l;
int x[maxn];
int b[maxn];
ld d[maxn];
int p[maxn];
vi ans;

bool check(ld k) {
	ms(d, 0);
	FOR(i, 1, n) {
		d[i] = INT_MAX;
		FOR(j, 0, i) if (d[i] > d[j] + sqrt(abs(x[i] - x[j] - l)) - k * b[i]) {d[i] = d[j] + sqrt(abs(x[i] - x[j] - l)) - k * b[i]; p[i] = j;}
	}
	return d[n - 1] >= 0;
}

void solve() {
	scanf("%d%d", &n, &l);
	FOR(i, 1, n + 1) scanf("%d%d", x + i, b + i);
	x[0] = 0; n++;
	ld l = 0; ld r = 1e18;
	while (r - l > 1e-9) {
		ld mid = (l + r) / 2;
		if (check(mid)) l = mid; else r = mid;
	}
	n--; while (n) {ans.push_back(n); n = p[n];}
	while (sz(ans)) {printf("%d ", ans.back()); ans.pop_back();}
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