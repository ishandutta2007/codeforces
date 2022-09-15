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
const ld EPS = 1e-6;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "-----\n";

const int maxn = 3000;
int n, P, k;
int f[maxn];
int g[maxn];
long long ff[maxn][100];
long long gg[maxn][100];
short dp[maxn][maxn][2];

void upd(int st1, int st2, int& pos, int& dif, int& fa) {
	if (st1 == -1) {
		pos = st2;
		dif = k;
		fa = 1;
	}
	else if (st2 == -1) {
		pos = st1;
		dif = k;
		fa = 0;
	}
	else if (st1 > st2) {
		pos = st1;
		dif = min(k, st1 - st2);
		fa = 0;
	}
	else {
		pos = st2;
		dif = min(k, st2 - st1);
		fa = 1;
	}
}

pi mem[maxn][55][55][2];
pi get(int pos, int dif, int fa, int st1, int st2, int i) {
	pi& res = mem[pos][dif][i - pos][fa];
	if (~res.fi) return res;
	long long msk1 = 0, msk2 = 0;
	if (~st1 && i - st1 <= 60) msk1 = ff[st1][k - 1] >> i - st1;
	if (~st2 && i - st2 <= 60) msk2 = gg[st2][k - 1] >> i - st2;
	res.fi = bitcount(ff[i][k - 1] ^ (ff[i][k - 1] & (msk1 | msk2)));
	res.se = bitcount(gg[i][k - 1] ^ (gg[i][k - 1] & (msk1 | msk2)));
	return res;
}

inline int id(int dif, int p) {
	return dif + p * (k + 2);
}

void solve() {
	cin >> n >> P >> k;
	int r; cin >> r;
	FOR(i, 0, r) {
		int u; cin >> u; u--;
		f[u] = 1;
	}
	int c; cin >> c;
	FOR(i, 0, c) {
		int u; cin >> u; u--;
		g[u] = 1;
	}
	if ((P / 2) * k >= n) {
		int ans = 0;
		FOR(i, 0, n) {
			if (f[i] || g[i]) {
				ans++;
			}
		}
		cout << ans << "\n";
		return;
	}
	FOR(i, 0, n) {
		ff[i][0] = f[i];
		FOR(j, i + 1, i + k) {
			ff[i][j - i] = ff[i][j - i - 1];
			if (f[j]) {
				ff[i][j - i] |= 1LL << j - i;
			}
		}
		gg[i][0] = g[i];
		FOR(j, i + 1, i + k) {
			gg[i][j - i] = gg[i][j - i - 1];
			if (g[j]) {
				gg[i][j - i] |= 1LL << j - i;
			}
		}
	}
	ms(mem, -1);
	FORd(pos, n, 0) FOR(dif, 0, k + 2) FOR(p, 0, P + 1) FOR(fa, 0, 2) {
		short& res = dp[pos][id(dif, p)][fa];
		if (!p) continue;
		int st1, st2;
		if (dif == k + 1) {
			st1 = st2 = -1;
		}	
		else if (!fa) {
			st1 = pos - 1;
			if (dif < k) {
				st2 = pos - dif;
			}
			else {
				st2 = -1;
			}
		}
		else {
			st2 = pos - 1;
			if (dif < k) {
				st1 = pos - dif;
			}
			else {
				st1 = -1;
			}
		}
		FOR(i, pos, pos + k) {
			pi tot = get(pos, dif, fa, st1, st2, i);
			int npos, ndif, nfa;
			upd(i, st2, npos, ndif, nfa);
			chkmax(res, short(dp[npos + 1][id(ndif, p - 1)][nfa] + tot.fi));
			upd(st1, i, npos, ndif, nfa);
			chkmax(res, short(dp[npos + 1][id(ndif, p - 1)][nfa] + tot.se));
		}
		chkmax(res, dp[pos + k][id(k + 1, p)][0]);
	}
	cout << dp[0][id(k + 1, P)][0] << "\n";
}

int main() {
	int JUDGE_ONLINE = 0;
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
        JUDGE_ONLINE = 1;
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    if (!JUDGE_ONLINE) {
    	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}