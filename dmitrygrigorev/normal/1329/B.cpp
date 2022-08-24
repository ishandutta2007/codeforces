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
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int a = 0; a < t; ++a) {

		int d, m;
		cin >> d >> m;

		vector<int> var;

		int cur = 1;

		while (cur <= d) {
			int l = cur, r = min(d, 2*cur - 1);
			var.push_back(r - l + 1);
			cur *= 2;
		}

		for (int i = 0; i < var.size(); ++i) {
			var[i]++;
		}

		int ans = 1;
		for (int i = 0; i < var.size(); ++i) {
			var[i] %= m;
			ans *= var[i];
			ans %= m;
		}
		ans--;
		ans %= m;
		if (ans < 0) ans += m;

		cout << ans << "\n";

	}

}