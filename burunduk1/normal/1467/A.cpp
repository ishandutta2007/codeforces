/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

const int N = 2e5 + 1;

vector<int> a(N);

void solve() {
	int n;
	cin >> n;
	forn(i, n) cout << a[i];
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);

	a[0] = 9;
	for (int d = 8, i = 1; i < N; i++, d = (d + 1) % 10)
		a[i] = d;

	int tn;
	cin >> tn;
	while (tn--)
		solve();
}