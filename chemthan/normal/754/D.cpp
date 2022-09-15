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
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int MAXN = 500000 + 10;
const int LOGN = 20;
int tr[LOGN + 1][MAXN];
long long sm[LOGN + 1][MAXN];
void insert(int x, int t) {
	for (int i = 0; i < LOGN; i++) {
		tr[i][x]++;
		sm[i][x] += t;
		x >>= 1;
	}
}
void erase(int x, int t) {
	for (int i = 0; i < LOGN; i++) {
		tr[i][x]--;
		sm[i][x] -= t;
		x >>= 1;
	}
}
long long kthelm(int k) {
	long long res = 0;
	int a = 0, b = LOGN;
	while (b--) {
		a <<= 1;
		k -= tr[b][a] < k ? tr[b][a++] : 0;
		res = sm[b][a] / tr[b][a];
	}
	return res;
}

const int maxn = 300000 + 10;
int n, k;
map<int, int> dc;
int l[maxn];
int r[maxn];
int rr[maxn];

int compare(int i, int j) {
	if (l[i] != l[j]) return l[i] < l[j];
	return i < j;
}

int calc(int f = INF + INF + 10) {
	ms(tr, 0), ms(sm, 0);
	int res = 0;
	vi v; FOR(i, 0, n) v.pb(i);
	sort(all(v), compare);
	int ptr = 0;
	FOR(j, 0, n) {
		int i = v[j];
		while (ptr < n) {
			int ii = v[ptr];
			if (l[ii] == l[i]) {
				insert(maxn - rr[ii], -r[ii]);
				ptr++;
			}
			else {
				break;
			}
		}
		if (ptr >= k) {
			int x = -kthelm(k);
			chkmax(res, x - l[i] + 1);
			if (res == f) {
				cout << res << "\n";
				for (int u = 0, cnt = 0; u < n && cnt < k; u++) {
					if (l[u] <= l[i] && r[u] >= x) {
						cout << u + 1 << " \n"[cnt == k - 1];
						cnt++;
					}
				}
				return res;
			}
		}
	}
	return res;
}

void solve() {
	cin >> n >> k;
	FOR(i, 0, n) {
		cin >> l[i] >> r[i];
		dc[r[i]];
	}
	int cnt = 0; FORall(it, dc) it->se = cnt++;
	FOR(i, 0, n) rr[i] = dc[r[i]];
	int mx = calc();
	calc(mx);
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