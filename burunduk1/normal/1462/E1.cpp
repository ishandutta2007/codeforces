/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

const int N = 2e5, M = 100;
int64_t C[N + 1][M + 1];

int64_t solve() {
	int n, m = 3, k = 2;
	int64_t ans = 0;
	cin >> n;// >> m >> k;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	sort(all(a));
	int r = 0;
	forn(l, n) {
		while (r < n && a[r] <= a[l] + k)
			r++;
		if (r - l >= m)
		ans += C[r - l - 1][m - 1];
	}
	return ans;
}

int main() {
	C[0][0] = 1;
	forn(i, N)
		forn(j, M)
			C[i+1][j+1] += C[i][j], C[i+1][j] += C[i][j];
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		cout << solve() << "\n";
}