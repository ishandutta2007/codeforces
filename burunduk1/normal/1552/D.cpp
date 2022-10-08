/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

void solve() {
	int n, ans = 0;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	function<void(int, int, int)> go = [&](int i, int sum, int k) {
		if (i == n) {
			ans |= (sum == 0 && k > 0);
			return;
		}
		go(i + 1, sum, k);
		go(i + 1, sum + a[i], k + 1);
		go(i + 1, sum - a[i], k + 1);
	};
	go(0, 0, 0);
	puts(ans ? "YES" : "NO");
}

int main() {
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}