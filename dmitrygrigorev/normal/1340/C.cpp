#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

ll dp[10007][1007];
pair<int, int> arr[20000007];
int ptr = 10000003;

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> d(m);
	for (int i = 0; i < m; ++i) cin >> d[i];

	sort(all(d));
	int g, r;
	cin >> g >> r;

	for (int i = 0; i < m; ++i) for (int j = 0; j < g; ++j) {
		dp[i][j] = 1e18;
	}

	dp[0][0] = 0;
	arr[ptr++] = make_pair(0, 0);

	int now = 10000003;
	while (now != ptr) {
		int a = arr[now].first, b = arr[now++].second;
		if (a != m-1) {
			int kek = b + (d[a+1] - d[a]);
			if (kek < g) {
				if (dp[a][b] < dp[a+1][kek]) {
					dp[a+1][kek] = dp[a][b];
					arr[--now] = make_pair(a+1, kek);
				}
			}
			else if (kek == g) {
				kek -= g;
				if (dp[a][b] + 1 < dp[a+1][kek]) {
					dp[a+1][kek] = dp[a][b] + 1;
					arr[ptr++] = make_pair(a+1, kek);
				}
			} 
		}	

		if (a != 0) {
			int kek = b + (d[a] - d[a-1]);
			if (kek < g) {
				if (dp[a][b] < dp[a-1][kek]) {
					dp[a-1][kek] = dp[a][b];
					arr[--now] = make_pair(a-1, kek);
				}
			}
			else if (kek == g) {
				kek -= g;
				if (dp[a][b] + 1 < dp[a-1][kek]) {
					dp[a-1][kek] = dp[a][b] + 1;
					arr[ptr++] = make_pair(a-1, kek);
				}
			} 
		}	
	}

	ll ans = 1e18;
	for (int i = 0; i < g; ++i) {
		if (dp[m-1][i] > 1e15) continue;
		if (i != 0) ans = min(ans, (ll) i + (ll) (r+g) * dp[m-1][i]);
		else ans = min(ans, (ll) (r+g) * (dp[m-1][i]-1) + g);
	} 
	if (ans==1e18) cout << -1;
	else cout << ans;

}