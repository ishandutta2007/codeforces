/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

void solve() {
	int x1, y1, x2, y2, px, py;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> px >> py;
	int ans = abs(x1 - x2) + abs(y1 - y2);
	if ((x1 == x2 || y1 == y2) && 
		min(x1, x2) <= px && px <= max(x1, x2) &&
		min(y1, y2) <= py && py <= max(y1, y2))
		ans += 2;
	cout << ans << "\n";
}
int main() {
	int tn;
	cin >> tn;
	while (tn--) solve();
}