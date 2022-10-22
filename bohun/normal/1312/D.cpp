#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>
#define ull unsigned long long

using namespace std;

const int MOD = 998244353;

LL pt(LL a, LL b) {
	if (!b) return 1;
	if (b & 1) return a * pt(a, b - 1) % MOD;
	return pt(a * a % MOD, b / 2);
}

int n, m;

int main() {
	int ans = 1;
	scanf ("%d%d", &n, &m);
	if (n == 2) {
		printf ("0\n");
		return 0;
	}
	rep(i, 1, n - 3) ans = (LL) ans * 2 % MOD;
	n = n - 1;
	rep(i, m - n + 1, m) ans = (LL) ans * i % MOD;
	rep(i, 1, n) ans = (LL) ans * pt(i, MOD - 2) % MOD;
	printf ("%lld", (LL) ans * (n - 1) % MOD);

	return 0;
}