#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
#ifndef ONPC
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> sum(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			sum[i] = sum[i - 1] + x;
		}
		int sol = n;
		for (int i = 0; i <= n; i++) {
			sol = min(sol, max(sum[i], n - i - sum[n] + sum[i]));
		}
		cout << sol << "\n";
	}
	return 0;
}