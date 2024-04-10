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

const int maxn = 400010;
int n;
int x[maxn];
int y[maxn];
int z[maxn];
int t[maxn];
vii hor[maxn];
vii ver[maxn];
map<int, int> dc;
int rb[maxn];
vii q[maxn];

ll st[4 * maxn];
ll lz[4 * maxn];
void update(int node, int l, int r, int L, int R) {
	if (lz[node]) {
		st[node] += lz[node] * (R - L + 1);
		if (L < R) {
			lz[node << 1] += lz[node];
			lz[(node << 1) + 1] += lz[node];
		}
		lz[node] = 0;
	}
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		st[node] += R - L + 1;
		if (L < R) {
			lz[node << 1]++;
			lz[(node << 1) + 1]++;
		}
		return;
	}
	update(node << 1, l, r, L, (L + R) >> 1);
	update((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R);
	st[node] = st[node << 1] + st[(node << 1) + 1];
}
ll query(int node, int l, int r, int L, int R) {
	if (lz[node]) {
		st[node] += lz[node] * (R - L + 1);
		if (L < R) {
			lz[node << 1] += lz[node];
			lz[(node << 1) + 1] += lz[node];
		}
		lz[node] = 0;
	}
	if (l > R || r < L) return 0;
	if (l <= L && r >= R) return st[node];
	return query(node << 1, l, r, L, (L + R) >> 1) + query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R);
}

vii process(vii v) {
	vii res;
	int cur, nxt = -INF;
	FOR(i, 0, sz(v)) {
		if (nxt < v[i].fi) {
			if (nxt > -INF) res.pb(mp(cur, nxt));
			cur = v[i].fi;
			nxt = v[i].se;
		}
		else nxt = max(nxt, v[i].se);
	}
	if (nxt > -INF) res.pb(mp(cur, nxt));
	return res;
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%d%d%d%d", x + i, y + i, z + i, t + i);
		dc[x[i]]; dc[y[i]]; dc[z[i]]; dc[t[i]];
	}
	int cnt = 0;
	FORall(it, dc) {
		it->se = cnt;
		rb[cnt++] = it->fi;
	}
	FOR(i, 0, n) {
		x[i] = dc[x[i]]; y[i] = dc[y[i]];
		z[i] = dc[z[i]]; t[i] = dc[t[i]];
		if (y[i] == t[i]) {
			if (x[i] > z[i]) swap(x[i], z[i]);
			hor[y[i]].pb(mp(x[i], z[i]));
		}
		else {
			if (y[i] > t[i]) swap(y[i], t[i]);
			ver[x[i]].pb(mp(y[i], t[i]));
		}
	}
	ll ans = 0;
	FOR(i, 0, maxn) {
		sort(all(hor[i]));
		sort(all(ver[i]));
		hor[i] = process(hor[i]);
		ver[i] = process(ver[i]);
		FOR(j, 0, sz(ver[i])) {
			int u = ver[i][j].fi;
			int v = ver[i][j].se;
			if (u) q[u - 1].pb(mp(i, 1));
			q[v].pb(mp(i, -1));
			ans += rb[v] - rb[u] + 1;
		}
	}
	FOR(i, 0, maxn) {
		FOR(j, 0, sz(hor[i])) {
			update(1, hor[i][j].fi, hor[i][j].se, 0, maxn - 1);
			ans += rb[hor[i][j].se] - rb[hor[i][j].fi] + 1;
		}
		FOR(j, 0, sz(q[i])) {
			ans += q[i][j].se * query(1, q[i][j].fi, q[i][j].fi, 0, maxn - 1);
		}
	}
	printf("%I64d", ans);
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