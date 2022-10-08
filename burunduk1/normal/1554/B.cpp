/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

const int M = 500;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int64_t val = -1e18;
	forn(i, min(n, M))
		forn(j, i) {
			int64_t i1 = n - i - 1, j1 = n - j - 1;
			val = max(val, (i1 + 1) * (j1 + 1) - k * (a[i1] | a[j1]));
		}
	cout << val << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}