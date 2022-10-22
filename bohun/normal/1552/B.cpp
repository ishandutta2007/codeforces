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
		vector<vector<int>> v(n, vector<int> (5, 0));
		for (auto& i : v)
			for (auto& j : i)
				cin >> j;

		auto who = [&](int a, int b) {
			int cnt = 0;
			for (int i = 0; i < 5; i++)
				cnt += (v[a][i] < v[b][i] ? 1 : -1);
			return cnt > 0;
		};

		int best = 0;
		for (int i = 1; i < n; i++)
			if (who(i, best))
				best = i;

		bool ok = 1;
		for (int i = 0; i < n; i++)
			if (i != best)
				ok &= who(best, i);

		cout << (ok ? best + 1 : -1) << endl;
	}

	return 0;
}