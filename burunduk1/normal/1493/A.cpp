/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

void solve() {
	int n, k;
	cin >> n >> k;
	
	vector<int> r;
	for (int i = n; 2 * i >= k; i--)
		if (i != k)
			r.push_back(i);
	cout << r.size() << "\n";
	for (int x : r) cout << x << " ";
	cout << "\n";	
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}