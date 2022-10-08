/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

void solve() {
	string s, t;
	cin >> s >> t;
	int ans = 0;
	forn(i, t.size() - 1)
		ans += abs((int)s.find(t[i]) - (int)s.find(t[i + 1]));
	cout << ans << "\n";
}

int main() {
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}