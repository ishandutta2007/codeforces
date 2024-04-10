/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int tn;
	cin >> tn;
	while (tn--) {
		int n, a, b, k = 0;
		cin >> n >> a, n--;
		while (n--) {
			cin >> b;
			auto go = [&](int x, int y) {
				while (2 * x < y)
					x *= 2, k++;
			};
			go(min(a, b), max(a, b));
			a = b;
		}
		cout << k << "\n";
	}
}