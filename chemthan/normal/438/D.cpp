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

const int maxn = 100010;
int n, m;
int a[maxn];

ll st[4 * maxn][2];
void build(int node, int L, int R) {
	if (L == R) {
		st[node][0] = st[node][1] = a[L];
		return;
	}
	build(node << 1, L, (L + R) >> 1);
	build((node << 1) + 1, ((L + R) >> 1) + 1, R);
	st[node][0] = st[node << 1][0] + st[(node << 1) + 1][0];
	st[node][1] = max(st[node << 1][1], st[(node << 1) + 1][1]);
}
void update(int node, int l, int r, int L, int R, int x) {
	if (l > R || r < L) return;
	if (L == R) {
		st[node][0] %= x;
		st[node][1] = st[node][0];
		return;
	}
	if (st[node][1] < x) {
		return;
	}
	update(node << 1, l, r, L, (L + R) >> 1, x);
	update((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R, x);
	st[node][0] = st[node << 1][0] + st[(node << 1) + 1][0];
	st[node][1] = max(st[node << 1][1], st[(node << 1) + 1][1]);
}
void update(int node, int i, int L, int R, int x) {
	if (i < L || i > R) return;
	if (L == R) {
		st[node][0] = st[node][1] = x;
		return;
	}
	update(node << 1, i, L, (L + R) >> 1, x);
	update((node << 1) + 1, i, ((L + R) >> 1) + 1, R, x);
	st[node][0] = st[node << 1][0] + st[(node << 1) + 1][0];
	st[node][1] = max(st[node << 1][1], st[(node << 1) + 1][1]);
}
ll query(int node, int l, int r, int L, int R) {
	if (l > R || r < L) return 0;
	if (l <= L && r >= R) return st[node][0];
	return query(node << 1, l, r, L, (L + R) >> 1) + query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R);
}

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) scanf("%d", a + i);
	build(1, 0, n - 1);
	while (m--) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int l, r; scanf("%d%d", &l, &r); l--; r--;
			printf("%I64d\n", query(1, l, r, 0, n - 1));
		}
		else if (op == 2) {
			int l, r, x; scanf("%d%d%d", &l, &r, &x); l--; r--;
			update(1, l, r, 0, n - 1, x);
		}
		else if (op == 3) {
			int k, x; scanf("%d%d", &k, &x); k--;
			update(1, k, 0, n - 1, x);
		}
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