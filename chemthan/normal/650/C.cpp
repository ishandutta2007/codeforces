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
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
const ld EPS = 1e-9;
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 1000010;
int n, m;
vector<vi> a;
vi row, col;
vi vx(maxn);

int dj[maxn];
int val[maxn];
void init(int k) {
	FOR(i, 0, k) {
		dj[i] = i;
		val[i] = vx[i];
	}
}
int find(int u) {
	return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
void join(int u, int v) {
	int p = find(u);
	int q = find(v);
	if (p != q) {
		dj[p] = q;
		setmax(val[q], val[p]);
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	a.resize(n);
	row.resize(n); col.resize(m);
	priority_queue<pair<int, pi> > pq;
	vi vrow[n], vcol[m];
	FOR(i, 0, n) {
		a[i].resize(m);
		FOR(j, 0, m) {
			scanf("%d", &a[i][j]);
			pq.push(mp(-a[i][j], mp(i, j)));
		}
	}
	while (sz(pq)) {
		int u = -pq.top().fi;
		vii v; v.pb(pq.top().se);
		pq.pop();
		while (sz(pq) && pq.top().fi == -u) {
			v.pb(pq.top().se);
			pq.pop();
		}
		FOR(i, 0, sz(v)) vx[i] = 0;
		vi hisx, hisy;
		FOR(i, 0, sz(v)) {
			int x = v[i].fi;
			int y = v[i].se;
			setmax(vx[i], row[x] + 1);
			setmax(vx[i], col[y] + 1);
			vrow[x].pb(i);
			vcol[y].pb(i);
			hisx.pb(x);
			hisy.pb(y);
		}
		sort(all(hisx)); sort(all(hisy));
		uni(hisx); uni(hisy);
		init(sz(v));
		FOR(i, 0, sz(hisx)) {
			int x = hisx[i];
			FOR(j, 1, sz(vrow[x])) {
				join(vrow[x][j], vrow[x][0]);
			}
		}
		FOR(i, 0, sz(hisy)) {
			int y = hisy[i];
			FOR(j, 1, sz(vcol[y])) {
				join(vcol[y][j], vcol[y][0]);
			}
		}
		FOR(i, 0, sz(v)) {
			int x = v[i].fi;
			int y = v[i].se;
			int p = find(i);
			a[x][y] = val[p];
			setmax(row[x], a[x][y]);
			setmax(col[y], a[x][y]);
		}
		FOR(i, 0, sz(hisx)) {
			int x = hisx[i];
			vrow[x].clear();
		}
		FOR(i, 0, sz(hisy)) {
			int y = hisy[i];
			vcol[y].clear();
		}
	}
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
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