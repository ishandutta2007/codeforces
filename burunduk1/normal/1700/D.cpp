/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);

	int n, a;
	cin >> n;
	vector<pair<int64_t, int64_t>> t(n + 1);
	int64_t s = 0;
	t[0] = {0, 1};
	forn(i, n) {
		cin >> a;
		s += a, t[i + 1] = {s, i + 1};
		if (t[i].first * t[i + 1].second > t[i + 1].first * t[i].second) // t[i] > t[i + 1]
			t[i + 1] = t[i];
	}

	int64_t q, T;
	cin >> q;
	forn(i, q) {
		cin >> T;
		int l = 0, r = n + 1;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (t[m].first <= T * t[m].second && m * T >= s) // t[m] <= T
				r = m;
			else
				l = m;
		}
		cout << (r > n ? -1 : r) << "\n";
	}
}