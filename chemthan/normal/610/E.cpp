#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 200010;
int n, m, k;
char s[maxn];
char t[maxn];

int st[4 * maxn][10][10];
pi lz[4 * maxn];
void init() {
	FOR(i, 0, 4 * maxn) lz[i] = mp(-1, -1);
}
void updatelz(int node, int L, int R) {
	if (lz[node] != mp(-1, -1)) {
		ms(st[node], 0);
		int u = lz[node].fi;
		int v = lz[node].se;
		st[node][u][v] = R - L + 1;
		if (L < R) {
			lz[node << 1] = lz[node];
			lz[(node << 1) + 1] = lz[node];
		}
		lz[node] = mp(-1, -1);
	}
}
void update(int node, int l, int r, int L, int R, int a, int b) {
	updatelz(node, L, R);
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		ms(st[node], 0);
		st[node][a][b] = R - L + 1;
		if (L < R) {
			lz[node << 1] = mp(a, b);
			lz[(node << 1) + 1] = mp(a, b);
		}
		return;
	}
	update(node << 1, l, r, L, (L + R) >> 1, a, b);
	update((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R, a, b);
	FOR(i, 0, 10) FOR(j, 0, 10) st[node][i][j] = st[node << 1][i][j] + st[(node << 1) + 1][i][j];
}
int query(int node, int l, int r, int L, int R, int a, int b) {
	updatelz(node, L, R);
	if (l > R || r < L) return 0;
	if (l <= L && r >= R) return st[node][a][b];
	return query(node << 1, l, r, L, (L + R) >> 1, a, b) + query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R, a, b);
}

struct SegmentTree {
	int st[4 * maxn];
	int lz[4 * maxn];
	SegmentTree() {
		FOR(i, 0, 4 * maxn) lz[i] = -1;
	}
	void updatelz(int node, int L, int R) {
		if (~lz[node]) {
			st[node] = lz[node] * (R - L + 1);
			if (L < R) {
				lz[node << 1] = lz[node];
				lz[(node << 1) + 1] = lz[node];
			}
			lz[node] = -1;
		}
	}
	void update(int node, int l, int r, int L, int R, int a) {
		updatelz(node, L, R);
		if (l > R || r < L) return;
		if (l <= L && r >= R) {
			st[node] = a * (R - L + 1);
			if (L < R) {
				lz[node << 1] = a;
				lz[(node << 1) + 1] = a;
			}
			return;
		}
		update(node << 1, l, r, L, (L + R) >> 1, a);
		update((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R, a);
		st[node] = st[node << 1] + st[(node << 1) + 1];
	}
	int query(int node, int l, int r, int L, int R) {
		updatelz(node, L, R);
		if (l > R || r < L) return 0;
		if (l <= L && r >= R) return st[node];
		return query(node << 1, l, r, L, (L + R) >> 1) + query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R);
	}
} smt;

void solve() {
	scanf("%d%d%d%s", &n, &m, &k, s);
	FOR(i, 0, n - 1) update(1, i, i, 0, n - 1, s[i] - 'a', s[i + 1] - 'a');
	FOR(i, 0, n) smt.update(1, i, i, 0, n - 1, s[i] - 'a');
	while (m--) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int l, r; char c[10]; scanf("%d%d%s", &l, &r, c); l--; r--;
			update(1, l, r - 1, 0, n - 1, c[0] - 'a', c[0] - 'a');
			smt.update(1, l, r, 0, n - 1, c[0] - 'a');
			if (l) {
				int k = smt.query(1, l - 1, l - 1, 0, n - 1);
				update(1, l - 1, l - 1, 0, n - 1, k, c[0] - 'a');
			}
			if (r < n - 1) {
				int k = smt.query(1, r + 1, r + 1, 0, n - 1);
				update(1, r, r, 0, n - 1, c[0] - 'a', k);
			}
		}
		else {
			scanf("%s", t);
			int ans = 0;
			FOR(i, 0, k) FOR(j, i + 1, k) {
				ans += query(1, 0, n - 1, 0, n - 1, t[i] - 'a', t[j] - 'a');
			}
			printf("%d\n", n - ans);
		}
	}
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}