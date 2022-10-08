/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int solve() {
	int n, sum = 0;
	cin >> n;
	vector<int> a(n);
	forn(i, n)
		cin >> a[i];
	auto f = [&](int i) {
		return 0 < i && i + 1 < n && ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]));
	};
	forn(i, n)
		sum += f(i);
	int opt = sum;
	forn(i, n) {
		int tmp = a[i], d = f(i - 1) + f(i) + f(i + 1);
		auto relax = [&](int x) {
			a[i] = x;
			// printf("a[%d] = %d : %d - %d + %d\n", i, x, sum, d, f(i - 1) + f(i) + f(i + 1));
			opt = min(opt, sum - d + f(i - 1) + f(i) + f(i + 1));
			a[i] = tmp;
		};
		relax(i > 0 ? a[i - 1] : 0);
		relax(i + 1 < n ? a[i + 1] : 0);
	}
	// printf("opt = %d\n", opt);
	return opt;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		cout << solve() << "\n";
}