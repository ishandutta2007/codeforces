/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

void solve() {
	int x, y, n;
	pair<int, int> ans = {INT_MAX, 0};
	cin >> n >> x >> y;
	for (int st = 1; st <= x; st++)
		for (int d = 1; d <= y - x; d++) {
			int en = st + d * (n - 1);
			if ((st - x) % d == 0 && (y - x) % d == 0 && en >= y)
				ans = min(ans, {en, d});
		}
	forn(i, n)
		cout << ans.first - ans.second * (n - 1 - i) << " ";
	cout << "\n";
}

int main() {
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}