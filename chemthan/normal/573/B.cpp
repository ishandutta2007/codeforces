#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 100010;
int n;
int h[maxn];

int st[2][4 * maxn];
void build(int node, int L, int R) {
	if (L == R) {st[0][node] = h[L] + L; st[1][node] = h[L] - L; return;}
	build(node << 1, L, (L + R) >> 1);
	build((node << 1) + 1, ((L + R) >> 1) + 1, R);
	st[0][node] = min(st[0][node << 1], st[0][(node << 1) + 1]);
	st[1][node] = min(st[1][node << 1], st[1][(node << 1) + 1]);
}
int query1(int node, int l, int r, int L, int R) {
	if (l > R || r < L) return INT_MAX;
	if (l <= L && r >= R) return st[0][node];
	return min(query1(node << 1, l, r, L, (L + R) >> 1), query1((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R));
}
int query2(int node, int l, int r, int L, int R) {
	if (l > R || r < L) return INT_MAX;
	if (l <= L && r >= R) return st[1][node];
	return min(query2(node << 1, l, r, L, (L + R) >> 1), query2((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R));
}

bool check(int mid) {
	FOR(i, 1, n + 1) {
		int k = query1(1, i, min(n + 1, i + mid), 0, n + 1) - mid - i;
		int l = query2(1, max(0, i - mid), i, 0, n + 1) - mid + i;
		int d = min(min(k, l), h[i] - mid);
		if (d > 0) return false;
	}
	return true;
}

void solve() {
	ms(h, 0); ms(st, 0);
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", h + i + 1);
	build(1, 0, n + 1);
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (!check(mid)) l = mid + 1; else r = mid;
	}
	printf("%d", l);
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