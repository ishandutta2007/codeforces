/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main() {
	int tn;
	cin >> tn;
	while (tn--) {
		int n;
		cin >> n;
		vector<pair<int, int>> a(n);
		forn(i, n)
			cin >> a[i].first, a[i].second = i;
		sort(all(a));

		int l = -1, r = 1e9;
		while (r - l > 1) {
			int m = (l + r) / 2;
			int64_t sum = 0, bad = 0;
			forn(i, n) {
				int x = a[i].first;
				bad |= x > sum && x > m, sum += x;
			}
			(bad ? l : r) = m;
		}
		// printf(" %d %d\n", l, r);

		vector<int> id;
		for (auto [x, i] : a)
			if (x >= r)
				id.push_back(i);
		sort(all(id));

		cout << id.size() << "\n";
		for (int i : id) cout << i + 1 << " ";
		cout << "\n";
	}
}