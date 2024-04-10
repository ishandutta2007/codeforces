#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
	int t;
    cin >> t;

    while (t--) {
		int n;
		cin >> n;

		vector<int> a(n + 1), x(n + 1), id(n), ans(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (int i = 1; i < n; ++i) {
			x[i] = max(0, a[i] - a[i + 1]);
			id[i] = i;
		}

		sort(id.begin() + 1, id.begin() + n, [&](int i, int j) {
			return x[i] < x[j];
		});

		for (int i = n - 1; i >= 1; --i) {
			ans[i + 1] = id[i] + 1;
		}
		ans[1] = n;

		for (int i = 1; i <= n; ++i) {
			cout << ans[i] << " \n"[i == n];
		}
	}
	
	return 0;
}