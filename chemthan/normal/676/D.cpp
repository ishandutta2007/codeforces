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

const int maxn = 1010;
int n, m;
int a[4][maxn][maxn];
int dist[maxn][maxn][4];

int rotate(int msk) {
	int a[4] = {};
	FOR(i, 0, 4) a[i] = bit(msk, i);
	int res = 0;
	FOR(i, 0, 4) {
		int nxt = (i + 3) % 4;
		res += a[nxt] * (1 << i);
	}
	return res;
}

void solve() {
	cin>>n>>m;
	FOR(i, 0, n) {
		string s; cin>>s;
		FOR(j, 0, m) {
			if (s[j] == '+') {
				a[0][i][j] = (1 << 0) + (1 << 1) + (1 << 2) + (1 << 3);
			}
			else if (s[j] == '-') {
				a[0][i][j] = (1 << 1) + (1 << 3);
			}
			else if (s[j] == '|') {
				a[0][i][j] = (1 << 0) + (1 << 2);
			}
			else if (s[j] == '^') {
				a[0][i][j] = (1 << 0);
			}
			else if (s[j] == '>') {
				a[0][i][j] = (1 << 1);
			}
			else if (s[j] == '<') {
				a[0][i][j] = (1 << 3);
			}
			else if (s[j] == 'v') {
				a[0][i][j] = (1 << 2);
			}
			else if (s[j] == 'L') {
				a[0][i][j] = (1 << 0) + (1 << 1) + (1 << 2) + (1 << 3) - (1 << 3);
			}
			else if (s[j] == 'R') {
				a[0][i][j] = (1 << 0) + (1 << 1) + (1 << 2) + (1 << 3) - (1 << 1);
			}
			else if (s[j] == 'U') {
				a[0][i][j] = (1 << 0) + (1 << 1) + (1 << 2) + (1 << 3) - (1 << 0);
			}
			else if (s[j] == 'D') {
				a[0][i][j] = (1 << 0) + (1 << 1) + (1 << 2) + (1 << 3) - (1 << 2);
			}
		}
	}
	FOR(i, 0, n) FOR(j, 0, m) {
		FOR(k, 1, 4) {
			a[k][i][j] = rotate(a[k - 1][i][j]);
		}
	}
	int xt, yt, xm, ym; cin>>xt>>yt>>xm>>ym; xt--; yt--; xm--; ym--;
	queue<pair<int, pair<pi, int> > > pq;
	ms(dist, 0x3f); dist[xt][yt][0] = 0;
	pq.push(mp(dist[xt][yt][0], mp(mp(xt, yt), 0)));
	while (sz(pq)) {
		int x = pq.front().se.fi.fi;
		int y = pq.front().se.fi.se;
		int z = pq.front().se.se;
		int w = pq.front().fi;
		pq.pop();
 		if (dist[x][y][z] != w) {
			continue;
		}
		if (x < n - 1 && bit(a[z][x][y], 2) && bit(a[z][x + 1][y], 0)) {
			if (chkmin(dist[x + 1][y][z], dist[x][y][z] + 1)) {
				pq.push(mp(dist[x + 1][y][z], mp(mp(x + 1, y), z)));
			}
		}
		if (x && bit(a[z][x][y], 0) && bit(a[z][x - 1][y], 2)) {
			if (chkmin(dist[x - 1][y][z], dist[x][y][z] + 1)) {
				pq.push(mp(dist[x - 1][y][z], mp(mp(x - 1, y), z)));
			}
		}
		if (y < m - 1 && bit(a[z][x][y], 1) && bit(a[z][x][y + 1], 3)) {
			if (chkmin(dist[x][y + 1][z], dist[x][y][z] + 1)) {
				pq.push(mp(dist[x][y + 1][z], mp(mp(x, y + 1), z)));
			}
		}
		if (y && bit(a[z][x][y], 3) && bit(a[z][x][y - 1], 1)) {
			if (chkmin(dist[x][y - 1][z], dist[x][y][z] + 1)) {
				pq.push(mp(dist[x][y - 1][z], mp(mp(x, y - 1), z)));
			}
		}
		if (chkmin(dist[x][y][(z + 1) % 4], dist[x][y][z] + 1)) {
			pq.push(mp(dist[x][y][(z + 1) % 4], mp(mp(x, y), (z + 1) % 4)));
		}
	}
	int ans = INF;
	FOR(i, 0, 4) {
		chkmin(ans, dist[xm][ym][i]);
	}
	if (ans == INF) ans = -1;
	cout<<ans<<"\n";
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