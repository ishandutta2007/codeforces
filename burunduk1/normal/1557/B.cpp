/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

void solve() {
	int n, k, cc = 0;
	cin >> n >> k;
	vector<pair<int, int>> a(n);
	for (auto &[x, i] : a) cin >> x, i = cc++;
	sort(all(a));
	
	int id = -2, cnt = 0;
	for (auto [x, i] : a)
		cnt += (i != id + 1), id = i;
	cout << (cnt <= k ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}