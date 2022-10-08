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
	vector<int> a(n), ma, mi;
	for (int &x : a) cin >> x;

	char c;
	forn(i, n) {
		cin >> c;
		if (c == 'R')
			ma.push_back(a[i]);
		else
			mi.push_back(a[i]);
	}
	sort(all(mi));
	sort(all(ma));

	bool bad = 0;
	forn(i, mi.size())
		bad |= mi[i] < i + 1;
	forn(i, ma.size())
		bad |= ma[i] > n - (int)ma.size() + i + 1;
	cout << (bad ? "NO" : "YES") << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}