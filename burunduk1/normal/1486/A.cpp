/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void solve() {
	int n, a, bad = 0;
	int64_t sum = 0;
	cin >> n;
	forn(i, n) {
		cin >> a, sum += a;
		bad |= (sum < i * (i + 1) / 2);
	}
	cout << (bad ? "NO\n" : "YES\n");
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}