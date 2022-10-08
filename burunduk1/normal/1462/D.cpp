/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int solve() {
	int n, sum = 0;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x, sum += x;
	for (int i = 1, s = 0; i <= n; i++) {
		s += a[i - 1];
		if (sum % s == 0) {
			int j = i, s2 = 0, bad = 0;
			while (j < n)
				s2 += a[j++], bad |= s2 > s, s2 %= s;
			if (!bad)
				return n - sum / s;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		cout << solve() << "\n";
}