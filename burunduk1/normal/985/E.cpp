/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);

	int n, k, d;
	cin >> n >> k >> d;
	vector<int> a(n), f(n + 1);
	forn(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	f[0] = 1;
	int l = 0, F = 0;
	for (int i = k; i <= n; i++) {
		F += f[i - k];
		while (a[i - 1] - a[l] > d && i - l >= k) 
			F -= f[l++];
		f[i] = (F > 0);
		// printf("f[%d] = %d (l = %d, F = %d)\n", i, f[i], l, F);
	}
	cout << (f[n] ? "YES" : "NO") << endl;
}