#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int MAXN = 21;
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
	matrix operator + (matrix A) {
		matrix res;
		for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
			res.x[i][j] = (x[i][j] + A.x[i][j]) % MOD;
		}
		return res;
	}
	matrix operator * (matrix A) {
		matrix res;
		for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
			for (int k = 0; k < MAXN; k++) res.x[i][j] = (res.x[i][j] + 1LL * x[i][k] * A.x[k][j]) % MOD;
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
		matrix tmp = sumpower(A, k);
		return tmp + (tmp * (A ^ k));
	}
};

const int maxn = 21;
int n, m, q;
int g[maxn][maxn];

int get(int i, int j) {
	return i * m + j;
}

void solve() {
	scanf("%d%d%d", &n, &m, &q);
	FOR(i, 0, n) FOR(j, 0, m) {
		g[get(i, j)][get(i, j)] = 1;
		if (i) g[get(i, j)][get(i - 1, j)] = 1;
		if (i + 1 < n) g[get(i, j)][get(i + 1, j)] = 1;
		if (j) g[get(i, j)][get(i, j - 1)] = 1;
		if (j + 1 < m) g[get(i, j)][get(i, j + 1)] = 1;
	}
	int cur = 1;
	matrix can, A;
	can.x[0][0] = 1; FOR(i, 0, maxn) FOR(j, 0, maxn) A.x[i][j] = g[i][j];
	while (q--) {
		int op, x, y, t; scanf("%d%d%d%d", &op, &x, &y, &t);
		int k = get(x - 1, y - 1);
		can = can * (A ^ (t - cur - 1));
		if (op == 1) {
			can = can * A;
			printf("%d\n", can.x[0][k]);
		}
		else if (op == 2) {
			FOR(i, 0, maxn) A.x[i][k] = 0;
			can = can * A;
		}
		else {
			can = can * A;
			FOR(i, 0, maxn) A.x[i][k] = g[i][k];
		}
		cur = t;
	}
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}