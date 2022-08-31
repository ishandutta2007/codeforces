/*
Hanit Banga
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5, S = 6, M = 3;
const ll INF = 1e15;

ll dp[N][S][M], a[N][M];

ll mx(int i, int j);

int main()
{
	int n;
	cin >> n;

	for (int j = 0; j < M; ++j)
		for (int i = 0; i < n; ++i)
			cin >> a[i][j];

	for (int i = 0; i < n; ++i)
		for (int s = 0; s < S; ++s)
			for (int j = 0; j < M; ++j)
				dp[i][s][j] = -INF;

	dp[0][0][0] = a[0][0];
	dp[0][0][1] = a[0][0] + a[0][1];
	dp[0][0][2] = a[0][0] + a[0][1] + a[0][2];
	dp[0][1][0] = a[0][0];
	dp[0][4][0] = a[0][0];
	dp[0][4][1] = a[0][0] + a[0][1];

	for (int i = 1; i < n; ++i)
	{
		for (int s = 1; s <= 3; ++s)
		{
			dp[i][s][s - 1] = a[i][s - 1] + mx(i - 1, s - 1);
		}

		dp[i][4][1] = a[i][0] + a[i][1] + mx(i - 1, 0);
		dp[i][4][0] = a[i][0] + a[i][1] + mx(i - 1, 1);

		dp[i][5][1] = a[i][1] + a[i][2] + mx(i - 1, 2);
		dp[i][5][2] = a[i][1] + a[i][2] + mx(i - 1, 1);

		dp[i][0][0] = a[i][0] + a[i][1] + a[i][2] + mx(i - 1, 2);
		dp[i][0][2] = a[i][0] + a[i][1] + a[i][2] + mx(i - 1, 0);

		dp[i][0][2] = max(dp[i][0][2], dp[i - 1][1][0] + a[i - 1][1] + a[i - 1][2] + a[i][0] + a[i][1] + a[i][2]);
		dp[i][0][0] = max(dp[i][0][0], dp[i - 1][3][2] + a[i - 1][0] + a[i - 1][1] + a[i][0] + a[i][1] + a[i][2]);
	}

	cout << mx(n - 1, 2);
}

ll mx(int i, int j)
{
	ll ans = -INF;
	for (int s = 0; s < S; ++s)
		ans = max(ans, dp[i][s][j]);
	return ans;
}