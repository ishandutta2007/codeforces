#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int tn;
	cin >> tn;
	while (tn--) {
		int n, k, l, r, h, fail = 0;
		cin >> n >> k;
		cin >> h, n--, r = l = h;
		// puts("-");
		while (n--) {
			cin >> h;
			fail |= l > r;
			l = max(h, l - (k - 1));
			r = min(h + k - 1, r + (k - 1));
			// printf("h = %d | l = %d, r = %d\n", h, l, r);
		}
		r = min(r, h);
		cout << (!fail && l <= r ? "YES" : "NO") << "\n";
	}
}