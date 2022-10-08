/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int ask(int l, int r) {
	if (l == r)
		return -1;
	int x;
	cout << "? " << l + 1 << " " << r + 1 << endl;
	cin >> x;
	return x - 1;
}

void ans(int i)  {
	cout << "! " << i + 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);

	int n;
	cin >> n;
	int m2 = ask(0, n - 1);
	if (ask(0, m2) == m2) {
		int l = 0, r = m2;
		while (r - l > 1) {
			int m = (l + r) / 2;
			(ask(m, m2) == m2 ? l : r) = m;
		}
		ans(l);
	} else {
		int l = m2, r = n - 1;
		while (r - l > 1) {
			int m = (l + r) / 2;
			(ask(m2, m) == m2 ? r : l) = m;
		}
		ans(r);
	}
}