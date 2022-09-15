#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 100010;
const int maxd = 110;
const int mod = 1000000007;
int n, x;
int cnt[maxd];
ll f[maxd];

struct matrix {
	ll x[maxd][maxd];
	matrix() {ms(x, 0);}
};

matrix mul(matrix A, matrix B) {
	matrix res;
	FOR(i, 0, maxd) FOR(j, 0, maxd) FOR(k, 0, maxd) res.x[i][j] = (res.x[i][j] + A.x[i][k] * B.x[k][j]) % mod;
	return res;
}

matrix ex(matrix A, int k) {
	if (k == 1) return A;
	matrix res = A, tmp = A; k--;
	while (k) {
		if (k & 1) res = mul(res, tmp);
		tmp = mul(tmp, tmp);
		k >>= 1;
	}
	return res;
}

ll cal(int x) {
	if (x <= 100) return f[x];
	matrix A, B;
	FOR(i, 0, 100) A.x[0][i] = f[100 - i]; A.x[0][100] = 1;
	FOR(i, 0, 100) B.x[i][0] = cnt[i + 1]; B.x[100][0] = 1;
	FOR(i, 0, 99) B.x[i][i + 1] = 1; B.x[100][100] = 1;
	matrix res = mul(A, ex(B, x - 100));
	return res.x[0][0];
}

void solve() {
	ms(cnt, 0); ms(f, 0);
	scanf("%d%d", &n, &x);
	FOR(i, 0, n) {int d; scanf("%d", &d); cnt[d]++;}
	FOR(i, 0, 101) {
		f[i] = 1;
		FOR(j, 1, 101) if (i >= j) f[i] = (f[i] + 1LL * cnt[j] * f[i - j]) % mod;
	}
	printf("%I64d", cal(x));
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}