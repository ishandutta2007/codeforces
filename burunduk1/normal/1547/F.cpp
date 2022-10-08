/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int solve() {
	int n, k = 18;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(k));
	unordered_set<int> s;
	forn(i, n)
		cin >> a[i][0], s.insert(a[i][0]);
	if (s.size() == 1u)
		return 0;

	forn(j, k - 1)
		forn(i, n)
			a[i][j + 1] = __gcd(a[i][j], a[(i + (1 << j)) % n][j]);
	vector<int> b(n, 0), c(n, 0);

	int ans = 0;
	for (int j = k - 1; j >= 0; j--) {
		s.clear();
		forn(i, n)
			s.insert(c[i] = __gcd(b[i], a[(i + ans) % n][j]));
		if (s.size() > 1u)
			b.swap(c), ans += 1 << j;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		cout << solve() << "\n";
}