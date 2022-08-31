#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int dp[4707][4707];
const int INF = 1e9;

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> agressy(n);
	for (int i = 0; i < n; ++i) cin >> agressy[i];

	vector<int> payment(n);
	for (int i = 0; i < n; ++i) {
		cin >> payment[i];
	}

	vector<int> cost(n+m);
	for (int i = 0; i < n+m; ++i) cin >> cost[i];

	for (int i = 0; i < n; ++i) {
		payment[i] -= cost[agressy[i] - 1];
	}

	for (int i=0; i < 4707; ++i) for (int j = 0; j < 4707; ++j) dp[i][j] = -INF;
	
	for (int i = 0; i < 4707; ++i) {
		dp[i][0] = 0;
	}

	for (int i = n-1; i >= 0; i--) {
		int pay = payment[i];
		vector<int> add(4707, -INF);
		for (int was = n-i-1; was >= 0; was--) {
			int T = was+1, D = agressy[i];
			int val = dp[D][was] - pay;
			while (T > 0) {
				dp[D][T] = max(dp[D][T], val);
				val += (T/2) * cost[D];
				D++;
				T /= 2;
			}
			add[D] = max(add[D], val);
		}
		int kek = -INF;
		for (int j = 0; j < 4707; ++j) {
			kek = max(kek, add[j]);
			dp[j][0] = max(dp[j][0], kek);
		}
		//if (i==1) cout << dp[3][0] << endl;
	}

	int ans = 0;
	for (int i = 0; i < 4707; ++i) for (int j = 0; j < 2; ++j) {
		ans = max(ans, dp[i][j]);
	}

	cout << ans;

}