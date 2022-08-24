#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v;

	set<int> tet;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		tet.insert(x);
		v.push_back(x);
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		int ans = 1488;
		int x;
		cin >> x;

		for (int j = 0; j < n; ++j) {
			if (x%v[j] == 0) ans = min(ans, x / v[j]);
		}

		for (int j = 0; j < n; ++j) {
			for (int take=1; take < k; ++take) {
				int rem = x - take * v[j];
				if (rem > 0) {
					for (int t = 1; t+take <= k; ++t) {
						if (rem % t == 0) {
							if (tet.count(rem/t)) {
								ans = min(ans, t+take);
							}
						}
					}
				}
			}
		}

		if (ans>k) cout << "-1\n";
		else cout << ans << "\n";
	}

}