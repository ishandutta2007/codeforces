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
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 30010;
const int MAGIC = 300;
int n, m, q;
int a[maxn];
vector<pair<pi, int> > que;
int cnt;
map<int, int> dc;
int rb[maxn];
int tot[maxn];
int ans[maxn];

const int MAXN = 3;
struct matrix {
	int x[MAXN][MAXN];
	matrix() {
		memset(x, 0, sizeof(x));
	}
	void zero() {
		memset(x, 0, sizeof(x));
	}
	void unit() {
		for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) x[i][j] = i == j;
	}
	matrix operator + (matrix A) {
		matrix res;
		for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
			res.x[i][j] = x[i][j] + A.x[i][j];
			if (res.x[i][j] >= m) res.x[i][j] -= m;
		}
		return res;
	}
	matrix operator * (matrix A) {
		matrix res;
		for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
			for (int k = 0; k < MAXN; k++) {
				res.x[i][j] += x[i][k] * A.x[k][j];
			}
			res.x[i][j] %= m;
		}
		return res;
	}
};

matrix st[4 * maxn];
void update(int u, int val) {
    u += n;
    if (!~val) st[u].unit();
    else {
    	st[u].x[0][0] = st[u].x[0][1] = 1; st[u].x[0][2] = 0;
    	st[u].x[1][0] = 1; st[u].x[1][1] = st[u].x[1][2] = 0;
    	st[u].x[2][0] = st[u].x[2][1] = val; st[u].x[2][2] = 1;
    }	
    for (u >>= 1; u; u >>= 1) st[u] = st[(u << 1) + 1] * st[u << 1];
}

matrix query(int l, int r) {
    matrix rl, rr; rl.unit(); rr.unit();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) rl = st[l++] * rl;
        if (r & 1) rr = rr * st[--r];
    }
    return rr * rl;
}

void add(int d) {
	if (!tot[d]++) update(d, rb[d]);
}

void del(int d) {
	if (!--tot[d]) update(d, -1);
}

int compare(pair<pi, int> a, pair<pi, int> b) {
	if (a.fi.fi / MAGIC != b.fi.fi / MAGIC) return a.fi.fi / MAGIC < b.fi.fi / MAGIC;
	return mp(a.fi.se, a.se) < mp(b.fi.se, b.se);
}

void solve() {
	FOR(i, 0, 4 * maxn) st[i].unit();
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {
		scanf("%d", a + i);
		dc[a[i]];
	}
	FORall(it, dc) {
		it->se = cnt;
		rb[cnt++] = it->fi % m;
	}
	FOR(i, 0, n) a[i] = dc[a[i]];
	scanf("%d", &q);
	FOR(i, 0, q) {
		int l, r; scanf("%d%d", &l, &r); l--; r--;
		que.pb(mp(mp(l, r), i));
	}
	sort(all(que), compare);
	int l = 0, r = -1;
	FOR(i, 0, sz(que)) {
		int u = que[i].fi.fi;
		int v = que[i].fi.se;
		int idx = que[i].se;
		if (r < v) {
			FOR(j, r + 1, v + 1) add(a[j]);
		}
		else {
			FOR(j, v + 1, r + 1) del(a[j]);
		}
		if (l > u) {
			FOR(j, u, l) add(a[j]);
		}
		else {
			FOR(j, l, u) del(a[j]);
		}
		ans[idx] = query(0, n).x[2][1];
		l = u; r = v;
	}
	FOR(i, 0, q) printf("%d\n", ans[i]);
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