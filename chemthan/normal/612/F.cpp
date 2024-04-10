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

const int maxn = 2010;
int n, s;
int a[maxn];
map<int, int> dc;
vi g[maxn];
int f[maxn];
pair<pi, int> rb[maxn];

int dist(int i, int j) {
	return min(abs(i - j), n - abs(i - j));
}

int dist2(int i, int j) {
	int res = j - i;
	if (res <= 0) res += n;
	return res;
}

vi trace(int p, int q, int dir) {
	vi res; res.pb(q);
	if (dir == 1) {
		while (q != p) {
			q = (q + 1) % n;
			if (a[q] == a[p]) {
				res.pb(q);
			}
		}
	}
	else {
		while (q != p) {
			q = (q + n - 1) % n;
			if (a[q] == a[p]) {
				res.pb(q);
			}
		}
	}
	return res;
}

void solve() {
	scanf("%d%d", &n, &s); s--;
	FOR(i, 0, n) {
		scanf("%d", a + i);
		dc[a[i]];
	}
	int cnt = 0; FORall(it, dc) it->se = cnt++;
	FOR(i, 0, n) {
		a[i] = dc[a[i]];
		g[a[i]].pb(i);
	}
	ms(f, 0x3f);
	FOR(i, 0, sz(g[0])) {
		int u = g[0][i];
		f[u] = dist(s, u);
		rb[u] = mp(mp(-1, s), 0);
	}
	FOR(i, 1, cnt) {
		FOR(j, 0, sz(g[i])) {
			int u = g[i][j];
			FOR(k, 0, sz(g[i - 1])) {
				int p = g[i - 1][k];
				int q = g[i - 1][(k + 1) % sz(g[i - 1])];
				int d = dist2(p, q);
				int x = f[p] + n - dist2(p, q) + dist(u, q);
				int y = f[q] + n - dist2(p, q) + dist(u, p);
				if (f[u] > x) {
					f[u] = x;
					rb[u] = mp(mp(p, q), 1);
				}
				if (f[u] > y) {
					f[u] = y;
					rb[u] = mp(mp(q, p), -1);
				}
			}
		}
	}
	int ans = INF, r1, r2, dir;
	FOR(i, 0, sz(g[cnt - 1])) {
		int p = g[cnt - 1][i];
		int q = g[cnt - 1][(i + 1) % sz(g[cnt - 1])];
		int x = f[p] + n - dist2(p, q);
		int y = f[q] + n - dist2(p, q);
		if (ans > x) {
			ans = x;
			r1 = p;
			r2 = q;
			dir = 1;
		}
		if (ans > y) {
			ans = y;
			r1 = q;
			r2 = p;
			dir = -1;
		}
	}
	printf("%d\n", ans);
	vi res;
	FOR(_, 0, cnt) {
		vi r = trace(r1, r2, dir);
		FOR(i, 0, sz(r)) res.pb(r[i]);
		pair<pi, int> p = rb[r1];
		r1 = p.fi.fi;
		r2 = p.fi.se;
		dir = p.se;
	}
	res.pb(r2); reverse(all(res));
	FOR(i, 0, sz(res) - 1) {
		if (res[i] <= res[i + 1] && res[i + 1] - res[i] == dist(res[i], res[i + 1])) printf("+");
		else if (res[i] >= res[i + 1] && res[i] - res[i + 1] != dist(res[i], res[i + 1])) printf("+");
		else printf("-");
		printf("%d\n", dist(res[i], res[i + 1]));
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