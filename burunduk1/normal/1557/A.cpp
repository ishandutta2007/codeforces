/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

void solve() {
	int n;
	double sum = 0, m = -1e18, x;
	cin >> n;
	forn(i, n)
		cin >> x, sum += x, m = max(m, x);
	printf("%.20f\n", m + (sum - m) / (n - 1));
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}