/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int MOD = 1e9 + 7;

struct IntMod {
	int x;
	IntMod(int x = 0) : x(x) { }
	void operator += (IntMod i) { x = (x + i.x) % MOD; }
	void operator -= (IntMod i) { x = (x - i.x + MOD) % MOD; }
	IntMod operator * (IntMod i) { return {(int)((int64_t)x * i.x % MOD)}; }
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);

	int n, k, q;
	cin >> n >> k >> q;
	vector<int> a(n);
	forn(i, n)
		cin >> a[i];
	
	vector<vector<IntMod>> f(k + 1, vector<IntMod>(n, 0));
	vector<IntMod> sum(n, 0);
	f[0] = vector<IntMod>(n, 1);
	forn(j, k) 
		forn(i, n) {
			if (i + 1 < n) f[j + 1][i + 1] += f[j][i];
			if (i > 0) f[j + 1][i - 1] += f[j][i];
		}
	forn(j, k + 1)
		forn(i, n)
			sum[i] += f[j][i] * f[k - j][i];

	IntMod ans = 0;
	forn(i, n)
		ans += sum[i] * a[i];
	while (q--) {
		int i, x;
		cin >> i >> x, i--;
		ans -= sum[i] * a[i];
		a[i] = x;
		ans += sum[i] * a[i];
		cout << ans.x << "\n";
	}
}