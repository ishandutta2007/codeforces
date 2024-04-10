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
	int a[n];
	forn(i, n)
		cin >> a[i];

	vector<vector<int>> answer;
	forn(i, n) {
		// [i,n)
		int j = min_element(a + i, a + n) - a;
		if (j != i) {
			answer.push_back({i + 1, n, j - i});
			rotate(a + i, a + j, a + n);
		}
	}
	cout << answer.size() << "\n";
	for (auto x : answer) {
		for (int i : x)
			cout << i << " ";
		cout << "\n";
	}
}

int main() {
	int tn;
	cin >> tn;
	while (tn--) 
		solve();
}