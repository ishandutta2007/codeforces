/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--) {
		int w, h, n, k = 1;
		cin >> w >> h >> n, w = w * h;
		while (w % 2 == 0) w /= 2, k *= 2;
		cout << (k >= n ? "YES\n" : "NO\n");
	}
}