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
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 9;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int MAXN = 2;
struct matrix {
	int x[MAXN][MAXN];
	matrix() {
		memset(x, 0, sizeof(x));
	}
	matrix unit() {
		matrix res;
		for (int i = 0; i < MAXN; i++) res.x[i][i] = 1;
		return res;
	}
	int iszero() {
		for (int i = 0; i < MAXN; i++) {
			for (int j = 0; j < MAXN; j++) {
				if (x[i][j]) return 0;
			}
		}
		return 1;
	}
	matrix operator + (matrix A) {
		matrix res;
		for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
			res.x[i][j] = (x[i][j] + A.x[i][j]) % MOD;
		}
		return res;
	}
	matrix operator - (matrix A) {
		matrix res;
		for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
			res.x[i][j] = (x[i][j] - A.x[i][j] + MOD) % MOD;
		}
		return res;
	}
	matrix operator * (matrix A) {
		matrix res;
		for (int i = 0; i < MAXN; i++) for (int k = 0; k < MAXN; k++) for (int j = 0; j < MAXN; j++) {
			res.x[i][j] = (res.x[i][j] + 1LL * x[i][k] * A.x[k][j]) % MOD;
		}
		return res;
	}
	matrix operator ^ (long long k) {
		if (!k) return unit();
		matrix res, tmp;
		for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
			res.x[i][j] = tmp.x[i][j] = x[i][j];
		}
		k--;
		while (k) {
			if (k & 1) res = res * tmp;
			tmp = tmp * tmp;
			k >>= 1;
		}
		return res;
	}
	friend matrix sumpower(matrix A, long long k) {
		if (k == 1) return A;
		if (k & 1) return (A ^ k) + sumpower(A, k - 1);
		k >>= 1;
		matrix T = sumpower(A, k);
		return T + (T * (A ^ k));
	}
};

const int maxn = 300010;
int n, m;
int a[maxn];
matrix A[maxn];
matrix B[maxn];
matrix C[maxn];

int st[4 * maxn];
matrix lz[4 * maxn];
void build(int node, int L, int R) {
	if (L == R) {st[node] = a[L]; return;}
	build(node << 1, L, (L + R) >> 1);
	build((node << 1) + 1, ((L + R) >> 1) + 1, R);
	st[node] = (st[node << 1] + st[(node << 1) + 1]) % MOD;
}
void updatelz(int node, int L, int R) {
	if (!lz[node].iszero()) {
		matrix D = C[R + 2] - C[L + 1];
		D = D * lz[node];
		st[node] = (st[node] + D.x[1][0]) % MOD;
		if (L < R) {
			lz[node << 1] = lz[node << 1] + lz[node];
			lz[(node << 1) + 1] = lz[(node << 1) + 1] + lz[node];
		}
		ms(lz[node].x, 0);
	}
}
void update(int node, int l, int r, int L, int R, matrix& val) {
	updatelz(node, L, R);
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		matrix D = C[R + 2] - C[L + 1];
		D = D * val;
		st[node] = (st[node] + D.x[1][0]) % MOD;
		if (L < R) {
			lz[node << 1] = lz[node << 1] + val;
			lz[(node << 1) + 1] = lz[(node << 1) + 1] + val;
		}
		return;
	}
	update(node << 1, l, r, L, (L + R) >> 1, val);
	update((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R, val);
	st[node] = (st[node << 1] + st[(node << 1) + 1]) % MOD;
}
int query(int node, int l, int r, int L, int R) {
	updatelz(node, L, R);
	if (l > R || r < L) return 0;
	if (l <= L && r >= R) return st[node];
	return (query(node << 1, l, r, L, (L + R) >> 1) + query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R)) % MOD;
}

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) scanf("%d", a + i);
	A[0] = A[0].unit(); A[1].x[0][0] = A[1].x[0][1] = A[1].x[1][0] = 1;
	FOR(i, 1, maxn) A[i] = A[i - 1] * A[1];
	B[0] = B[0].unit(); B[1].x[0][1] = B[1].x[1][0] = 1; B[1].x[1][1] = MOD - 1;
	matrix R = A[1] * B[1];
	FOR(i, 1, maxn) B[i] = B[i - 1] * B[1];
	FOR(i, 1, maxn) C[i] = C[i - 1] + A[i];
	build(1, 0, n - 1);
	while (m--) {
		int op, l, r; scanf("%d%d%d", &op, &l, &r); l--; r--;
		if (op == 1) {
			update(1, l, r, 0, n - 1, B[l + 1]);
		}
		else {
			printf("%d\n", query(1, l, r, 0, n - 1));
		}
	}
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}