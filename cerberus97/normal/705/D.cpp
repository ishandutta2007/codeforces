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

const int N = 5e3 + 5;
const ll INF = 1e15;

ll x[N], a[N], b[N], c[N], d[N], dp[2][N][2][2];

int main()
{
	int n, s, e;
	cin >> n >> s >> e;
	for (int i = 1; i <= n; ++i) cin >> x[i];
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	for (int i = 1; i <= n; ++i) cin >> c[i];
	for (int i = 1; i <= n; ++i) cin >> d[i];
	
	int prev = 0, cur = 1;
	for (int j = 0; j <= n + 1; ++j)
		for (int k = 0; k < 2; ++k)
			for (int l = 0; l < 2; ++l)
				dp[prev][j][k][l] = dp[cur][j][k][l] = INF;

	dp[prev][0][0][0] = 0;

	for (int i = 1; i <= n; ++i, swap(cur, prev))
	{
		for (int j = 0; j <= i; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				for (int l = 0; l < 2; ++l)
				{	
					dp[cur][j][k][l] = INF;
					
					if (i == s)
					{
						//Left
						if (l)
							dp[cur][j][k][l] = min(dp[cur][j][k][l], dp[prev][j + 1][k][l - 1] + c[i] + x[i]);
						
						if (!k)
							dp[cur][j][k][l] = min(dp[cur][j][k][l], dp[prev][j][k + 1][l] + c[i] + x[i]);

						//Right
						if (l)
							dp[cur][j][k][l] = min(dp[cur][j][k][l], dp[prev][j][k][l - 1] + d[i] - x[i]);
					}

					else if (i == e)
					{
						//Left
						if (k)
							dp[cur][j][k][l] = min(dp[cur][j][k][l], dp[prev][j + 1][k - 1][l] + a[i] + x[i]);
						
						if (!l)
							dp[cur][j][k][l] = min(dp[cur][j][k][l], dp[prev][j][k][l + 1] + a[i] + x[i]);

						//Right
						if (k)
							dp[cur][j][k][l] = min(dp[cur][j][k][l], dp[prev][j][k - 1][l] + b[i] - x[i]);
					}

					else
					{
						//LL
						if (j + k + l >= 1)
							dp[cur][j][k][l] = min(dp[cur][j][k][l], dp[prev][j + 1][k][l] + a[i] + c[i] + 2*x[i]);
						
						if (!j and !k and !l)
							dp[cur][j][k][l] = min(dp[cur][j][k][l], dp[prev][j][k + 1][l + 1] + a[i] + c[i] + 2*x[i]);

						//RR
						if (j)
							dp[cur][j][k][l] = min(dp[cur][j][k][l], dp[prev][j - 1][k][l] + b[i] + d[i] - 2*x[i]);

						//LR
						if (j + l >= 1)
							dp[cur][j][k][l] = min(dp[cur][j][k][l], dp[prev][j][k][l] + a[i] + d[i]);

						//RL
						if (j + k >= 1)
							dp[cur][j][k][l] = min(dp[cur][j][k][l], dp[prev][j][k][l] + b[i] + c[i]);
					}
				}
			}
		}
	}

	cout << dp[prev][0][0][0];
}