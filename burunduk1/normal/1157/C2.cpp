/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	forn(i, n) {
		cin >> a[i];
	}

	function<int(int,int,int)> solve = [&](int l, int r, int x) {
		if (l > r)
			return 0;
		if (a[l] > x && (a[r] <= x || a[r] > a[l]))
			return 1 + solve(l + 1, r, a[l]);
		if (a[r] > x && (a[l] <= x || a[r] < a[l]))
			return 1 + solve(l, r - 1, a[r]);
		if (a[l] > x && a[l] == a[r]) {
			int f1 = solve(l + 1, r, a[l]);
			int f2 = solve(l, r - 1, a[r]);
			// printf("l = %d r = %d x = %d : %d %d\n", l, r, x, f1, f2);
			return 1 + max(f1, f2);
		}
		return 0;
	};

	function<int(int,int,int)> solve2 = [&](int l, int r, int x) {
		if (l > r)
			return 0;
		if (a[l] > x && (a[r] <= x || a[r] > a[l])) {
			cout << 'L';
			return 1 + solve2(l + 1, r, a[l]);
		}
		if (a[r] > x && (a[l] <= x || a[r] < a[l])) {
			cout << 'R';
			return 1 + solve2(l, r - 1, a[r]);
		}
		if (a[l] > x && a[l] == a[r]) {
			int f1 = solve(l + 1, r, a[l]);
			int f2 = solve(l, r - 1, a[r]);
			if (f1 > f2) {
				cout << 'L';
				return 1 + solve2(l + 1, r, a[l]);
			} else {
				cout << 'R';
				return 1 + solve2(l, r - 1, a[r]);
			}
			// printf("l = %d r = %d x = %d : %d %d\n", l, r, x, f1, f2);
		}
		return 0;
	};

	int f = solve(0, n - 1, -1);
	cout << f << endl;
	solve2(0, n - 1, -1);
}