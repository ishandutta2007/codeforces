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

const int maxn = 15010;
const int maxk = 1010;
int n, k;
int v[maxn];
int w[maxn];
int l[maxn];
int r[maxn];
int f[maxk];
int p[maxk];
vii query;
vector<pair<int, pi> > itv;
priority_queue<pi> pq;

int compare(pair<int, pi> a, pair<int, pi> b) {
	return mp(mp(-a.se.fi, a.se.se), a.fi) < mp(mp(-b.se.fi, b.se.se), b.fi);
}

void add(int v, int w, vii& his) {
	FORd(i, k, 0) if (i + w <= k && f[i + w] < f[i] + v) {
		his.pb(mp(i + w, f[i + w]));
		f[i + w] = f[i] + v;
	}
}

void rollback(vii& his, vii& his2) {
	FORd(i, sz(his), 0) {
		int u = his[i].fi;
		int v = his[i].se;
		f[u] = v;
	}
	FOR(i, 0, sz(his2)) {
		pq.push(his2[i]);
	}
}

void go(int L, int R) {
	while (sz(itv) && itv.back().se.fi <= L) {
		pq.push(mp(itv.back().se.se, itv.back().fi));
		itv.pop_back();
	}
	vii his, his2;
	while (sz(pq) && pq.top().fi >= R) {
		int u = pq.top().se;
		add(v[u], w[u], his);
		his2.pb(pq.top());
		pq.pop();
	}
	if (L == R) {
		if (query[L].fi == 3) {
			int ans = 0, dmax = 0;
			FOR(i, 1, k + 1) {
				dmax = max(dmax, f[i]);
				ans = (ans + (ll) dmax * p[i - 1]) % MOD;
			}
			printf("%d\n", ans);
		}
	}
	else {
		go(L, (L + R) >> 1);
		go(((L + R) >> 1) + 1, R);
	}
	rollback(his, his2);
}

void solve() {
	p[0] = 1; FOR(i, 1, maxk) p[i] = 10000019LL * p[i - 1] % MOD;
	scanf("%d%d", &n, &k);
	FOR(i, 0, n) {
		scanf("%d%d", v + i, w + i);
		l[i] = i; r[i] = INF;
		query.pb(mp(1, i));
	}
	int q; scanf("%d", &q);
	while (q--) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int x, y; scanf("%d%d", &x, &y);
			v[n] = x; w[n] = y;
			l[n] = sz(query); r[n] = INF;
			query.pb(mp(op, n));
			n++;
		}
		else if (op == 2) {
			int x; scanf("%d", &x); x--;
			r[x] = sz(query) - 1;
			query.pb(mp(op, x));
		}
		else if (op == 3) {
			query.pb(mp(op, 0));
		}
	}
	FOR(i, 0, n) itv.pb(mp(i, mp(l[i], r[i])));
	sort(all(itv), compare);
	go(0, sz(query) - 1);
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}