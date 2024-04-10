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
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

int n, m;
vector<vi> a;

int check(vector<vi> res) {
	int n = sz(res), m = sz(res[0]);
	FOR(i, 0, n) FOR(j, 0, m) {
		FOR(u, -1, 2) FOR(v, -1, 2) {
			if (u != 0 || v != 0) {
				if (i + u >= 0 && i + u < n && j + v >= 0 && j + v < m) {
					if (res[i][j] == res[i + u][j + v]) {
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

int work(vector<vi>& res) {
	int n = sz(res), m = sz(res[0]);
	vector<vi> a = res;
	int p[] = {1, 2, 3, 4};
	do {
		int OK = 1;
		FOR(i, 0, n) {
			if (i & 1) {
				int ok = 1;
				FOR(j, 0, m) {
					if (j & 1) {
						res[i][j] = p[0];
					}
					else {
						res[i][j] = p[1];
					}
					if (a[i][j] && a[i][j] != res[i][j]) {
						ok = 0;
						break;
					}
				}
				if (!ok) {
					ok = 1;
					FOR(j, 0, m) {
						if (j & 1) {
							res[i][j] = p[1];
						}
						else {
							res[i][j] = p[0];
						}
						if (a[i][j] && a[i][j] != res[i][j]) {
							ok = 0;
							break;
						}
					}
				}
				if (!ok) {
					OK = 0;
					break;
				}
			}
			else {
				int ok = 1;
				FOR(j, 0, m) {
					if (j & 1) {
						res[i][j] = p[2];
					}
					else {
						res[i][j] = p[3];
					}
					if (a[i][j] && a[i][j] != res[i][j]) {
						ok = 0;
						break;
					}
				}
				if (!ok) {
					ok = 1;
					FOR(j, 0, m) {
						if (j & 1) {
							res[i][j] = p[3];
						}
						else {
							res[i][j] = p[2];
						}
						if (a[i][j] && a[i][j] != res[i][j]) {
							ok = 0;
							break;
						}
					}
				}
				if (!ok) {
					OK = 0;
					break;
				}
			}
		}
		if (OK && check(res)) {
			return 1;
		}
	}
	while (next_permutation(p, p + 4));
	return 0;
}

void solve() {
	cin>>n>>m;
	a.resize(n, vi(m, 0));
	FOR(i, 0, n) {
		string s; cin>>s;
		FOR(j, 0, m) a[i][j] = s[j] - '0';
	}
	vector<vi> res = a;
	if (work(res)) {
		FOR(i, 0, n) {
			FOR(j, 0, m) cout<<res[i][j];
			cout<<"\n";
		}
	}
	else {
		res.resize(m);
		FOR(i, 0, m) res[i].resize(n, 0);
		FOR(i, 0, n) FOR(j, 0, m) {
			res[j][i] = a[i][j];
		}
		if (work(res)) {
			FOR(i, 0, n) {
				FOR(j, 0, m) cout<<res[j][i];
				cout<<"\n";
			}
		}
		else {
			cout<<"0\n";
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