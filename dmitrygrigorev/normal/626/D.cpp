#include <bits/stdc++.h>
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int K = 20000;
const int N = 5000;

db dp[4][2*K+1];
int sum[2*N+1];

main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;	

	vector<int> v(n);

	dp[0][K] = 1;

	for (int i = 0; i < n; ++i) cin >> v[i];
		int tot = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		if (i==j) continue;
		if (v[i]>v[j]) tot++;
		sum[v[i]-v[j]+N]++;
	}


	for (int i = 0; i < 3; ++i) {
		for (int was = -N*i; was <= N*i; ++was) {
			for (int delta = -N; delta <= N; ++delta) {
				if (i < 2 && delta > 0) {
					dp[i+1][was+delta+K] += dp[i][was+K] * ((db) sum[delta+N] / (db) tot);
				}
				if (i==2 && delta < 0) {
					dp[i+1][was+delta+K] += dp[i][was+K] * ((db) sum[delta+N] / (db) tot);
				}
			}
		}
	}

	//cout << dp[2][2+K] << endl;

	db ans = 0;
	for (int i = -3*N; i < 0;++i) {
		ans += dp[3][i+K];
	}

	cout.precision(10);
	cout << fixed << ans;

	
}