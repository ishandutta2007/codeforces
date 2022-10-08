/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int64_t solve() {
	int n;
	cin >> n;
	int x[n], y[n];
	forn(i, n)
		cin >> x[i] >> y[i];
	if (n & 1)
		return 1;
	sort(x, x + n);
	sort(y, y + n);
	int a = n / 2, b = a - 1;
	return (int64_t)(x[a] - x[b] + 1) * (y[a] - y[b] + 1);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		cout << solve() << "\n";
}