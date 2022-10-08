/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a1, b1, a2, b2;
	auto read = [&](int n, vector<int> &p, vector<int> &neg) {
		forn(i, n) {
			int x;
			cin >> x;
			(x < 0 ? neg : p).push_back(abs(x));
		}
	};
	read(n, a1, a2);
	read(m, b1, b2);
	auto f = [&](vector<int> &a, vector<int> &b) {
		sort(all(a));
		sort(all(b));
		int j = a.size() - 1, sum = 0, ans = 0;
		for (int i = b.size() - 1; i >= 0; i--) {
			while (j >= 0 && a[j] > b[i])
				sum += (a[j--] == b[i]);
			int k = j + 1;
			int p = upper_bound(all(b), b[i] - k) - b.begin();
			// printf("i = %d, j = %d, k = %d, p = %d, sum = %d\n", i, j, k, p, sum);
			ans = max(ans, sum + i - p + 1);
			if (j >= 0 && a[j] == b[i])
				sum++, j--;
		}
		return ans;
	};
	cout << f(a1, b1) + f(a2, b2) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}