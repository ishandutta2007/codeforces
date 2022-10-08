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
		int n, c1 = 0, c2 = 0, a;
		cin >> n;
		while (n--)
			cin >> a, (a == 1 ? c1 : c2)++;
		cout << (c1 % 2 == 0 && (c1 >= 2 || c2 % 2 == 0) ? "YES\n" : "NO\n");
	}
}