#include <bits/stdc++.h>
#define ll __int128
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 100007;
ll INF = 1;

ll dp[N][10];
int dlt[N][10];

bool check(int x, int d) {
	if (x%2 == 0 && d % 2 != 0) return true;
	if (x%5 == 0 && d % 5 != 0) return true;
	return false;
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 36; ++i) INF *= 10;

	int n, d;
	cin >> n >> d;

	vector<int> v(n);
	for (auto &x : v) cin >> x;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 10; ++j) {
			dp[i][j] = -1;
		}
	}

	dp[0][1] = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (dp[i][j] == -1) continue;
			bool obligatory = check(v[i], d);
			if (obligatory) {
				if (dp[i][j] < dp[i+1][j] || dp[i+1][j] == -1) {
					dp[i+1][j] = dp[i][j];
					dlt[i+1][j] = -1;
				}
			}
			else {
				if (!((ll) dp[i][j] > INF / (ll) v[i])) {

				
					if (dp[i][j] * v[i] < dp[i+1][j] || dp[i+1][j] == -1) {
						dp[i+1][j] = dp[i][j] * v[i];
						dlt[i+1][j] = -1;
					}

				}
				int R = (j * v[i]) % 10;
				if (dp[i][j] < dp[i+1][R] || dp[i+1][R] == -1) {
					dp[i+1][R] = dp[i][j];
					dlt[i+1][R] = j;
				}
			}
		}
	}

	if (dp[n][d] == -1) {
		cout << -1;
		exit(0);
	}

	vector<int> ans;
	int a = n, b = d;
	while (a != 0) {
		if (dlt[a][b] == -1) {
			a--;
		}
		else {
			ans.pb(v[a-1]);
			b = dlt[a][b];
			a--;
		}
	}
	if (ans.size() == 0) {
		cout << -1;
		exit(0);
	}

	cout << ans.size() << '\n';
	for (auto x : ans) cout << x << " ";



}