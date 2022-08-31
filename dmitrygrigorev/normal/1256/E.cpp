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
	freopen("O_input.txt", "r", stdin);
	//freopen("O_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int> > v(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		v[i] = mp(x, i);
	}

	sort(all(v));
	vector<int> ans(n);

	vector<int> dp(n+1, -1e18);
	vector<int> opt(n+1);

	dp[0] = 0;

	int Q = -1e18, wh = -1;

	for (int i = 1; i <= n; ++i) {
		if (i >= 3) {
			if (dp[i-3] > Q) {
				//cout << Q << endl;
				Q = dp[i-3];
				//cout << Q << endl;
				wh = i-3;
			}
		}

		int R = Q;
		if (i < n) R += v[i].first - v[i-1].first;

		//cout << i << " " << R << endl;

		dp[i] = R;
		opt[i] = wh;

	}

	//cout << v[2].first << " " << v[3].first << endl;

	//cout << dp[3] << " " << dp[6] << endl;

	cout << v.back().first - v[0].first - dp.back() << " ";
	int teams = 0;

	int cur = n;

	while (cur != 0) {
		for (int i = opt[cur]; i < cur; ++i) {
			ans[v[i].second] = teams;
		}
		teams++;
		cur = opt[cur];
	}

	cout << teams << "\n";
	for (int i = 0; i < n; ++i) cout << ans[i]+1 << " ";




}