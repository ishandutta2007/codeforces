#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 3007;

bool allowed[N][N];
ll sum[N][N];

const ll INF = -1e18;
ll dp[N];
ll dp2[N];

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<vector<int> > v(n);
	for (auto &x : v) {
		int t;
		cin >> t;

		x.assign(t, -1);
		for (auto &el : x) cin >> el;
	}

int ta = 0;

	for (int len = 1; len <= k; ++len) {
		vector<pair<ll, int> > arr;
		for (int i = 0; i < n; ++i) {
			if (v[i].size() >= len) {
				sum[i][len] = sum[i][len-1] + v[i][len - 1];
				arr.pb(mp(sum[i][len], i));
			}
		}

		sort(all(arr), greater<pair<ll, int> > ());
		int can = (k + 2 * len - 1) / len;

		ta += min((int) arr.size(), can);

		int u = 0;
		while (u < arr.size() && u < can) {
			allowed[arr[u++].y][len] = true;
		}
	}

//	cout << ta << endl;

	for (int i = 0; i < N; ++i) dp[i] = INF;
	dp[0] = 0;

	for (int i = 0; i < n; ++i) {
		allowed[i][0] = true;
		if (v[i].size() < N) allowed[i][v[i].size()] = true;

		for (int i = 0; i < N; ++i) dp2[i] = INF;

		for (int j = 0; j <= k; ++j) {
			if (allowed[i][j]) {
				for (int was = k-j; was >= 0; was--) {
					dp2[was + j] = max(dp2[was + j], dp[was] + sum[i][j]);	
				}
			}
		}

		for (int i = 0; i < N; ++i) dp[i] = dp2[i];
	}

	cout << dp[k];

	

}