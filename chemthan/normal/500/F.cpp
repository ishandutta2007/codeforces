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

const int maxn = 4010;
const int maxc = 4010;
const int maxq = 20010;
int n, p, q;
int c[maxn];
int h[maxn];
int t[maxn];
int f[maxc];
vii query[maxq];
int ans[maxq];
vector<pair<pi, int> > itv;
priority_queue<pi> pq;

int compare(pair<pi, int> a, pair<pi, int> b) {
	return mp(mp(-a.fi.fi, a.fi.se), a.se) < mp(mp(-b.fi.fi, b.fi.se), b.se);
}

void add(int c, int h, vii& his) {
	FORd(i, maxc, 0) if (i + c < maxc && f[i + c] < f[i] + h) {
		his.pb(mp(i + c, f[i + c]));
		f[i + c] = f[i] + h;
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

void go(int l, int r) {
	vii his, his2;
	while (sz(itv) && itv.back().fi.fi <= l) {
		pq.push(mp(itv.back().fi.se, itv.back().se));
		itv.pop_back();
	}
	while (sz(pq) && pq.top().fi >= r) {
		int u = pq.top().se;
		add(c[u], h[u], his);
		his2.pb(pq.top());
		pq.pop();
	}
	if (l == r) {
		FOR(i, 0, sz(query[l])) {
			int u = query[l][i].fi;
			int v = query[l][i].se;
			ans[v] = f[u];
		}
	}
	else {
		go(l, (l + r) >> 1);
		go(((l + r) >> 1) + 1, r);
	}
	rollback(his, his2);
}

void solve() {
	scanf("%d%d", &n, &p);
	FOR(i, 0, n) {
		scanf("%d%d%d", c + i, h + i, t + i);
		itv.pb(mp(mp(t[i], t[i] + p - 1), i));
	}
	sort(all(itv), compare);
	scanf("%d", &q);
	FOR(i, 0, q) {
		int a, b; scanf("%d%d", &a, &b);
		query[a].pb(mp(b, i));
	}
	go(0, maxq - 1);
	FOR(i, 0, q) {
		printf("%d\n", ans[i]);
	}
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