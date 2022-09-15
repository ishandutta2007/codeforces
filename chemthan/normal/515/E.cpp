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

struct segment {
	int l, r;
	ll max;
	segment() {max = -1;}
} null;

const int maxn = 100010;
int n, m;
ll d[2 * maxn];
ll h[2 * maxn];
ll f[2 * maxn];

segment st[8 * maxn];

ll cal(int idx1, int idx2) {
	return h[idx1] + h[idx2] + f[idx2] - f[idx1];
}

segment merge(segment st1, segment st2) {
	if (st1.max == -1) return st2;
	if (st2.max == -1) return st1;
	segment res = st1.max > st2.max ? st1 : st2;
	ll tmp;
	if ((tmp = cal(st1.l, st2.l)) > res.max) {
		res.l = st1.l;
		res.r = st2.l;
		res.max = tmp;
	}
	if ((tmp = cal(st1.l, st2.r)) > res.max) {
		res.l = st1.l;
		res.r = st2.r;
		res.max = tmp;
	}
	if ((tmp = cal(st1.r, st2.l)) > res.max) {
		res.l = st1.r;
		res.r = st2.l;
		res.max = tmp;
	}
	if ((tmp = cal(st1.r, st2.r)) > res.max) {
		res.l = st1.r;
		res.r = st2.r;
		res.max = tmp;
	}
	return res;
}

void build(int node, int L, int R) {
	if (L == R) {st[node].l = st[node].r = L; st[node].max = 0; return;}
	build(node << 1, L, (L + R) >> 1);
	build((node << 1) + 1, ((L + R) >> 1) + 1, R);
	st[node] = merge(st[node << 1], st[(node << 1) + 1]);
}

segment query(int node, int l, int r, int L, int R) {
	if (l > R || r < L ) return null;
	if (l <= L && r >= R) return st[node];
	return merge(query(node << 1, l, r, L, (L + R) >> 1), query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R));
}

void solve() {
	ms(d, 0); ms(h, 0); ms(f, 0);
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) scanf("%I64d", d + i);
	FOR(i, 0, n) {scanf("%I64d", h + i); h[i] *= 2;}
	FOR(i, n, 2 * n) {d[i] = d[i - n]; h[i] = h[i - n];}
	FOR(i, 0, 2 * n) f[i + 1] = f[i] + d[i];
	build(1, 0, 2 * n - 1);
	while (m--) {
		int a, b; scanf("%d%d", &a, &b); a--;
		b %= n; a = (a + n - 1) % (n);
		if (a < b) a += n;
		printf("%I64d\n", query(1, b, a, 0, 2 * n - 1).max);
	}
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