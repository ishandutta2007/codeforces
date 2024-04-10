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

const int maxn = 1 << 10;
int n;
ll b[maxn][maxn];
ll c[maxn][maxn];
ll f[maxn][maxn];
ll g[maxn][maxn];
int rf[maxn][maxn];
int rg[maxn][maxn];

void solve() {
	cin>>n;
	int flag = 0;
	pi zero;
	FOR(i, 0, n) FOR(j, 0, n) {
		int a; cin>>a;
		if (a == 0) {
			b[i][j] = c[i][j] = LINF;
			flag = 1; zero = mp(i, j);
		}
		else {
			while (a % 2 == 0) {
				b[i][j]++;
				a /= 2;
			}
			while (a % 5 == 0) {
				c[i][j]++;
				a /= 5;
			}
		}
	}
	FOR(i, 0, n) FOR(j, 0, n) {
		f[i][j] = g[i][j] = LINF;
		rf[i][j] = rg[i][j] = -1;
	}
	f[n - 1][n - 1] = b[n - 1][n - 1];
	g[n - 1][n - 1] = c[n - 1][n - 1];
	FORd(i, n, 0) {
		FORd(j, n, 0) {
			if (i < n - 1) {
				if (f[i][j] > f[i + 1][j] + b[i][j] || !~rf[i][j]) {
					if (f[i][j] > f[i + 1][j] + b[i][j]) {
						f[i][j] = f[i + 1][j] + b[i][j];
					}
					rf[i][j] = 0;
				}
				if (g[i][j] > g[i + 1][j] + c[i][j] || !~rg[i][j]) {
					if (g[i][j] > g[i + 1][j] + c[i][j]) {
						g[i][j] = g[i + 1][j] + c[i][j];
					}
					rg[i][j] = 0;
				}
			}
			if (j < n - 1) {
				if (f[i][j] > f[i][j + 1] + b[i][j] || !~rf[i][j]) {
					if (f[i][j] > f[i][j + 1] + b[i][j]) {
						f[i][j] = f[i][j + 1] + b[i][j];
					}
					rf[i][j] = 1;
				}
				if (g[i][j] > g[i][j + 1] + c[i][j] || !~rg[i][j]) {
					if (g[i][j] > g[i][j + 1] + c[i][j]) {
						g[i][j] = g[i][j + 1] + c[i][j];
					}
					rg[i][j] = 1;
				}
			}
		}
	}
	if (min(f[0][0], g[0][0]) == LINF) {
		cout<<1<<"\n";
		FOR(i, 0, n - 1) cout<<"R";
		FOR(i, 0, n - 1) cout<<"D";
		cout<<"\n";
	}
	else if (flag && min(f[0][0], g[0][0]) > 1) {
		cout<<1<<"\n";
		int u = zero.fi;
		int v = zero.se;
		FOR(i, 0, u) cout<<"D";
		FOR(i, 0, v) cout<<"R";
		FOR(i, 0, n - u - 1) cout<<"D";
		FOR(i, 0, n - v - 1) cout<<"R";
		cout<<"\n";
	}
	else if (f[0][0] < g[0][0]) {
		cout<<f[0][0]<<"\n";
		pi cur = mp(0, 0);
		while (cur != mp(n - 1, n - 1)) {
			if (!rf[cur.fi][cur.se]) {
				cur.fi++;
				cout<<"D";
			}
			else {
				cur.se++;
				cout<<"R";
			}
		}
		cout<<"\n";
	}
	else {
		cout<<g[0][0]<<"\n";
		pi cur = mp(0, 0);
		while (cur != mp(n - 1, n - 1)) {
			if (!rg[cur.fi][cur.se]) {
				cur.fi++;
				cout<<"D";
			}
			else {
				cur.se++;
				cout<<"R";
			}
		}
		cout<<"\n";
	}
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