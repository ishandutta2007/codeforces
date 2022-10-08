/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> a(2, vector<int>(n));
	forn(row, 2) 
		forn(col, n)
			cin >> a[row][col];
	
	int ans = INT_MAX, left = 0, right = accumulate(all(a[0]), 0);
	forn(col, n) {
		right -= a[0][col];
		ans = min(ans, max(right, left));
		left += a[1][col];
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}