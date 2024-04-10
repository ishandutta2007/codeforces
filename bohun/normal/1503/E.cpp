#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
const int P = 998244353;

struct BinomialCoef {
	static constexpr int N = 1e6;
	int f[N], r[N];
	int power(int a, int b) {
		int res = 1;
		for (; b; b /= 2, a = 1ll * a * a % P)
			if (b & 1)
				res = 1ll * res * a % P;
		return res;
	}
	BinomialCoef() {
		f[0] = 1;
		rep(i, 1, N)
			f[i] = 1ll * f[i - 1] * i % P;
		r[N - 1] = power(f[N - 1], P - 2);
		per(i, 1, N)
			r[i - 1] = 1ll * r[i] * i % P;
	}
	int get(int n, int k) {
		if (n < k || k < 0) 
			return 0;
		return 1ll * f[n] * r[n - k] % P * r[k] % P;
	}
} C;

int n, m, suf[2030], res;

int main() {
	cin >> n >> m;

	for (int r = 0; r < 2; r++, swap(n, m)) {

		for (int i = 1; i <= m; i++) {

			auto ways = [&](int a, int b) {
				return C.get(a + b, b);
			};

			memset(suf, 0, sizeof suf);

			for (int j = n; 1 <= j; j--)
				suf[j] = (suf[j + 1] + 1ll * ways(m - (i + 1), j - 1) * ways(m - (i + 1) + 1, n - j)) % P;

			for (int j = 1; j <= n; j++)
				res = (res + 1ll * ways(n - j, i - 1) * ways(i - 1 + 1, j - 1) % P * suf[j + 1 + r]) % P;
		}

	}

	cout << 2 * res % P;
	return 0;
}