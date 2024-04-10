#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& i : a)
			cin >> i;
		int res = 0;
		for (int mask = 1; mask < pow(3, n); mask++) {
			int s = 0;
			int x = mask;
			for (int b = 0; b < n; b++) {
				int r = x % 3;
				x /= 3;
				if (r == 1)
					s += a[b];
				if (r == 2)
					s -= a[b];
			}
			if (s == 0)
				res = 1;
		}
		cout << (res ? "YES\n" : "NO\n");
	}
	return 0;
}