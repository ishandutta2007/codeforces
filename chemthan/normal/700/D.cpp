#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 100000 + 10;
const int magic = 320;
int n;
int a[maxn];
int c[maxn];
int head;
int fr[maxn];
int pv[maxn];
int nx[maxn];
long long ans[maxn];

void addl(int x) {
	if (!head) {
		head = x;
		fr[x] = 1;
		pv[x] = nx[x] = 0;
	}
	else {
		if (head > x) {
			fr[x]++;
			nx[x] = head;
			pv[head] = x;
			head = x;
		}
		else if (!(fr[x]++)) {
			if (fr[x - 1]) {
				nx[x] = nx[x - 1];
				pv[nx[x]] = x;
				nx[x - 1] = x;
				pv[x] = x - 1;
			}
			else {
				pv[x] = pv[x + 1];
				nx[pv[x]] = x;
				pv[x + 1] = x;
				nx[x] = x + 1;
			}
		}
	}
}

void reml(int x) {
	if (!(--fr[x])) {
		if (head == x) {
			head = nx[x];
		}
		int y = nx[x];
		int z = pv[x];
		nx[z] = y;
		pv[y] = z;
	}
}

inline void add(int k) {
	int x = ++c[a[k]];
	if (x > 0) addl(x);
	if (x - 1 > 0) reml(x - 1);
}

inline void rem(int k) {
	int x = --c[a[k]];
	if (x > 0) addl(x);
	if (x + 1 > 0) reml(x + 1);
}

queue<pi> q[2];
int cnt = 1;

pi top() {
	if (!sz(q[1])) {
		return q[0].front();
	}
	else if (!sz(q[0])) {
		return q[1].front();
	}
	else {
		if (q[0].front() < q[1].front()) {
			return q[0].front();
		}
		else {
			return q[1].front();
		}
	}
}
void pop(pi p) {
	if (!sz(q[1])) {
		if (q[0].front().se > p.se) {
			q[0].front().se -= p.se;
		}
		else {
			q[0].pop();
		}
	}
	else if (!sz(q[0])) {
		if (q[1].front().se > p.se) {
			q[1].front().se -= p.se;
		}
		else {
			q[1].pop();
		}
	}
	else {
		if (q[0].front() < q[1].front()) {
			if (q[0].front().se > p.se) {
				q[0].front().se -= p.se;
			}
			else {
				q[0].pop();
			}
		}
		else {
			if (q[1].front().se > p.se) {
				q[1].front().se -= p.se;
			}
			else {
				q[1].pop();
			}
		}
	}
	if (!sz(q[0])) {
		cnt = 0;
	}
	else if (!sz(q[1])) {
		cnt = 1;
	}
}
void push(pi p) {
	q[cnt].push(p);
}

long long getans() {
	while (sz(q[0])) q[0].pop();
	while (sz(q[1])) q[1].pop();
	for (int x = head; x; x = nx[x]) {
		push(mp(x, fr[x]));
	}
	long long ans = 0;
	while (sz(q[0]) + sz(q[1]) > 1 || top().se > 1) {
		int u = top().fi;
		int v = top().se;
		if (v > 1) {
			pop(mp(u, v / 2 * 2));
			push(mp(u << 1, v >> 1));
			ans += (long long) (u << 1) * (v >> 1);
		}
		else {
			pop(mp(u, v));
			int u2 = top().fi;
			int v2 = top().se;
			pop(mp(u2, 1));
			push(mp(u + u2, 1));
			ans += u + u2;
		}
	}
	return ans;
}

int compare(pair<pi, int> a, pair<pi, int> b) {
	if (a.fi.fi / magic != b.fi.fi / magic) return a.fi.fi / magic < b.fi.fi / magic;
	return a.fi.se < b.fi.se;
}

void solve() {
	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	int q; cin >> q;
	vector<pair<pi, int> > v;
	FOR(i, 0, q) {
		int l, r; cin >> l >> r; l--, r--;
		v.pb(mp(mp(l, r), i));
	}
	sort(all(v), compare);
	int l = 0, r = -1;
	FOR(i, 0, q) {
		int ll = v[i].fi.fi;
		int rr = v[i].fi.se;
		int ix = v[i].se;
		while (l > ll) add(--l);
		while (l < ll) rem(l++);
		while (r > rr) rem(r--);
		while (r < rr) add(++r);
		ans[ix] = getans();
	}
	FOR(i, 0, q) cout << ans[i] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}