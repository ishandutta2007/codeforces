/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n[3];
	int64_t sum = 0, ans = 1e18, m[3];
	forn(i, 3) 
		cin >> n[i];
	forn(i, 3) {
		vector<int> a(n[i]);
		int64_t sa = 0;
		for (int &x : a) cin >> x, sa += x;
		ans = min(ans, sa);
		sum += sa;
		m[i] = *min_element(all(a));
	}
	forn(i, 3)
		ans = min(ans, m[i] + m[(i + 1) % 3]);
	// cout << sum << " " << ans << endl;
	cout << sum - 2 * ans << endl;
}