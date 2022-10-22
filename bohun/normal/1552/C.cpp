#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(2 * n, 0), x(k, 0), y(k, 0);
		for (int i = 0; i < k; i++) {
			cin >> x[i] >> y[i];
			--x[i];
			--y[i];
			if (x[i] > y[i])
				swap(x[i], y[i]);
			a[x[i]] = 1;
			a[y[i]] = 1;
		}
		
		int rest = n - k;
		int res = rest * (rest - 1) / 2 + k * (k - 1) / 2;

		for (int i = 0; i < k; i++) {

			int c = count(a.begin() + x[i] + 1, a.begin() + y[i], 0);
			res += min(c, 2 * (n - k) - c);

			for (int j = 0; j < k; j++) {
				if (x[i] < x[j] && y[j] < y[i])
					res--;
				if (y[i] < x[j])
					res--;
			}
		}

		cout << res << endl;
	}

	return 0;
}