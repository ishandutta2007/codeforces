#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 3e5 + 100;
const int MOD = 998244353;

LL pt(LL a, LL b) {
	if (!b) return 1;
	if (b & 1) return a * pt(a, b - 1) % MOD;
	return pt(a * a % MOD, b / 2);
}

struct matrix {
	int t[2][2];
	
	matrix () {
		memset(t, 0, sizeof(t));
	}
	
	matrix operator *(matrix a) {
		matrix b = matrix();
		rep(k, 0, 1)
			rep(i, 0, 1)
				rep(j, 0, 1)
					b.t[i][j] = (b.t[i][j] + (LL) t[i][k] * a.t[k][j] % MOD) % MOD;
		return b;
	}
};

matrix pot(matrix a, LL k) {
	matrix res = matrix();
	res.t[0][0] = res.t[1][1] = 1;
	while (k) {
		if (k & 1) res = res * a;
		a = a * a;
		k /= 2;
	}
	return res;
}
	
LL n, m, l, r;	

int main() {
	scanf ("%lld %lld %lld %lld", &n, &m, &l, &r);
	LL z = n * m;
	LL x = r / 2 - (l - 1) / 2;
	LL y = (r - l + 1) - x;
	if (z % 2 == 1) {
		printf ("%lld\n", pt(r - l + 1, z));
		return 0;
	}
	matrix f = matrix();
	f.t[0][0] = 1;
	matrix M = matrix();
	M.t[0][0] = M.t[1][1] = y;
	M.t[0][1] = M.t[1][0] = x;
	M = pot(M, z);
	f = f * M;
	printf ("%d\n", f.t[0][0]);
	
	
	
    return 0;
}