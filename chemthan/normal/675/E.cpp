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

const int maxn = 100010;
const int maxe = 20;
int n;
int a[maxn];
int b[maxn][maxe];
ll sum[maxn][maxe];

ll calc(int k) {
	ll res = 0, t = 0;
	FORd(i, maxe, 0) {
		if (b[k][i] < n) {
			res += sum[k][i];
			k = b[k][i];
			t += 1 << i;
		}
	}
	return n * (t + 1) - res - sum[k][0];
}

int st[maxn << 2];
void build(int node, int L, int R) {
	if (L == R) {
		st[node] = L;
		return;
	}
	build(node << 1, L, L + R >> 1);
	build((node << 1) + 1, (L + R >> 1) + 1, R);
	st[node] = a[st[node << 1]] > a[st[(node << 1) + 1]] ? st[node << 1] : st[(node << 1) + 1];
}
int query(int node, int l, int r, int L, int R) {
	if (l > R || r < L) return -1;
	if (l <= L && r >= R) return st[node];
	int p = query(node << 1, l, r, L, L + R >> 1);
	int q = query((node << 1) + 1, l, r, (L + R >> 1) + 1, R);
	if (!~p) return q;
	if (!~q) return p;
	return a[p] > a[q] ? p : q;
}

void solve() {
	cin>>n;
	FOR(i, 1, n) cin>>a[i];
	build(1, 1, n);
	FOR(i, 1, n) {
		b[i][0] = query(1, i + 1, a[i], 1, n);
		sum[i][0] = i + a[i] - b[i][0];
	}
	b[n][0] = n;
	FOR(i, 1, maxe) FOR(j, 1, n + 1) {
		b[j][i] = b[b[j][i - 1]][i - 1];
		sum[j][i] = sum[j][i - 1] + sum[b[j][i - 1]][i - 1];
	}
	ll ans = 0;
	FOR(i, 1, n) ans += calc(i);
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