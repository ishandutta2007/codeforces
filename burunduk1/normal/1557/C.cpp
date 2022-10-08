/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9 + 7;

int mul(int a, int b) {
	return (int64_t)a * b % MOD;
}
void add(int &a, int b) {
	a = (a + b) % MOD;
}
int powm(int x, int n) {
	int r = 1;
	for (; n; n /= 2) {
		if (n & 1)
			r = mul(r, x);
		x = mul(x, x);
	}
	return r;
}

void solve() {
	int n, k;
	cin >> n >> k;

	int c0 = powm(2, n - 1), cless = c0, cmore = 0;
	if (n % 2 == 0)
		cmore++, c0--;
	else
		c0++, cless--;

	// printf("n=%d : c0=%d cless=%d cmore=%d\n", n, c0, cless, cmore);
	int ans = powm(c0, k);
	for (int m = 0; m < k; m++)
		add(ans, mul(mul(powm(c0, m), cmore), powm(powm(2, n), k - m - 1)));
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}