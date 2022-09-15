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
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 100 + 10;
int n, m;
map<string, int> hs;
string name[maxn];
string user[maxn];
string mess[maxn];
int g[maxn][maxn];
int f[maxn][maxn];
int ans[maxn];

int ff(int pos, int prv) {
	if (pos == m) return 1;
	int& res = f[pos][prv];
	if (~res) return res;
	res = 0;
	FOR(i, 0, n) {
		if (!g[pos][i] && i != prv) {
			res |= ff(pos + 1, i);
		}
	}
	return res;
}

void solve() {
	int test; cin >> test;
	while (test--) {
		hs.clear();
		ms(g, 0);
		cin >> n;
		FOR(i, 0, n) {
			cin >> name[i];
			hs[name[i]] = i;
		}
		cin >> m;
		cin.ignore();
		FOR(i, 0, m) {
			string s; getline(cin, s);
			int ix = s.find(":");
			user[i] = s.substr(0, ix);
			mess[i] = s.substr(ix + 1);
			string tmp = mess[i];
			FOR(j, 0, sz(tmp)) {
				if (!((tmp[j] >= 'a' && tmp[j] <= 'z') || (tmp[j] >= 'A' && tmp[j] <= 'Z') || (tmp[j] >= '0' && tmp[j] <= '9'))) {
					tmp[j] = ' ';
				}
			}
			stringstream ss(tmp);
			while (ss >> s) {
				if (hs.count(s)) {
					g[i][hs[s]] = 1;
				}
			}
			if (user[i] != "?") {
				int ix = hs[user[i]];
				FOR(j, 0, n) if (j != ix) {
					g[i][j] = 1;
				}
			}
		}
		ms(f, -1);
		if (!ff(0, n)) {
			cout << "Impossible\n";
		}
		else {
			int prv = n;
			FOR(i, 0, m) {
				FOR(j, 0, n) {
					if (!g[i][j] && j != prv) {
						if (ff(i + 1, j)) {
							ans[i] = j;
							break;
						}
					}
				}
				prv = ans[i];
			}
			FOR(i, 0, m) cout << name[ans[i]] << ":" << mess[i] << "\n";
		}
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