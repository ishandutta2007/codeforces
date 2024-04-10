/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

void solve() {
	int suma = 0, sumb = 0, n;
	cin >> n;
	vector<int> a(n), b(n);
	forn(i, n) cin >> a[i], suma += a[i];
	forn(i, n) cin >> b[i], sumb += b[i];
	if (suma != sumb) {
		cout << "-1\n";
		return;
	}
	vector<pair<int, int>> res;
	for (int run = 1; run; ) {
		run = 0;
		forn(i, n)
			forn(j, n)
				if (a[i] < b[i] && a[j] > b[j]) {
					a[i]++, a[j]--;
					res.push_back({j, i});
					run = 1;
				}
	}
	cout << res.size() << "\n";
	for (auto [a, b] : res) cout << a + 1 << " " << b + 1 << "\n";
}

int main() {
	int tn;
	cin >> tn;
	while (tn--) solve();
}