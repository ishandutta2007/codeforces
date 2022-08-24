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
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v(m);
	for (int i = 0; i < m; ++i) cin >> v[i];

	int sum = 0;
	for (int i = 0; i < m; ++i) sum += v[i];
	if (sum < n) {
		cout << "-1\n";
		exit(0);
	}

	int l = 0, r = v[m-1] - 1;
	vector<int> ans(m);
	ans[m-1] = 0;

	int remaining = sum - v[m-1];

	for (int i = m-2; i >= 0; i--) {
		int pt = max(0LL, r + 1 - v[i] + 1);

		remaining -= v[i];
		int tet = n - pt-v[i];

		pt += max(0LL, tet-remaining);

		ans[i] = pt;
		r = pt + v[i]-1;
		if (r >= n) {
			cout << "-1\n";
			exit(0);
		}
	}

	for (int i = 0; i < m; ++i) cout << ans[i]+1 << " ";

}