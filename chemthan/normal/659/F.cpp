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
const ld PI = acos((ld) -1);
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

const int maxn = 1010;
int n, m;
ll k;
int a[maxn][maxn];
int f[maxn][maxn];
int deg[maxn][maxn];

int dj[maxn * maxn];
int sz[maxn * maxn];
int mm[maxn * maxn];
void init() {
	FOR(i, 0, n * m) dj[i] = i, sz[i] = 1, mm[i] = a[i / m][i % m];
}
int find(int u) {
	return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
void join(int u, int v) {
	int p = find(u);
	int q = find(v);
	if (p != q) {
		dj[p] = q;
		sz[q] += sz[p];
		setmin(mm[q], mm[p]);
	}
}

int get(int u, int v) {
	return u * m + v;
}

int vis[maxn][maxn];
int cnt;

void dfs(int u, int v) {
	vis[u][v] = 1; cnt--;
	if (!cnt) return;
	if (u && !vis[u - 1][v] && f[u - 1][v]) dfs(u - 1, v);
	if (!cnt) return;
	if (u < n - 1 && !vis[u + 1][v] && f[u + 1][v]) dfs(u + 1, v);
	if (!cnt) return;
	if (v && !vis[u][v - 1] && f[u][v - 1]) dfs(u, v - 1);
	if (!cnt) return;
	if (v < m - 1 && !vis[u][v + 1] && f[u][v + 1]) dfs(u, v + 1);
}

void solve() {
	cin>>n>>m>>k;
	priority_queue<pair<int, pi> > pq;
	FOR(i, 0, n) FOR(j, 0, m) cin>>a[i][j], pq.push(mp(a[i][j], mp(i, j)));
	init();
	vector<ll> vx;
	set<ll> st;
	FOR(i, 0, n) FOR(j, 0, m) {
		if (k % a[i][j] == 0) {
			vx.pb(a[i][j]);
			st.insert(k / a[i][j]);
		}
	}
	sort(all(vx)); uni(vx); reverse(all(vx));
	int cur = 0;
	while (sz(pq)) {
		int d = pq.top().fi;
		while (cur < sz(vx) && vx[cur] > d) {
			st.erase(k / vx[cur++]);
		}
		ll dmin = sz(st) ? *st.begin() : LINF;
		int u = pq.top().se.fi;
		int v = pq.top().se.se;
		pq.pop();
		f[u][v] = 1;
		if (u && f[u - 1][v]) {
			join(get(u, v), get(u - 1, v));
		}
		if (u < n - 1 && f[u + 1][v]) {
			join(get(u, v), get(u + 1, v));
		}
		if (v && f[u][v - 1]) {
			join(get(u, v), get(u, v - 1));
		}
		if (v < m - 1 && f[u][v + 1]) {
			join(get(u, v), get(u, v + 1));
		}
		int p = find(get(u, v));
		if (sz[p] >= dmin && mm[p] == k / dmin) {
			cout<<"YES\n";
			int found = 0;
			FOR(i, 0, n) if (!found) {
				FOR(j, 0, m) {
					if (find(get(i, j)) == p && a[i][j] == k / dmin) {
						found = 1;
						cnt = dmin;
						dfs(i, j);
						break;
					}
				}
			}
			FOR(i, 0, n) {
				FOR(j, 0, m) {
					if (vis[i][j]) {
						cout<<k / dmin<<" ";
					}
					else {
						cout<<0<<" ";
					}
				}
				cout<<"\n";
			}
			return;
		}
	}
	cout<<"NO\n";
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