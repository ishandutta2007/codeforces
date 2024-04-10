#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define fo(i, n) for(int i = 0; n > i; ++i)
using namespace std;
const int nax = 100005, mod = 1e9 + 7;
int n, k, m;
int dp[nax][15][(1 << 4)];
void add(int &a, int b)
{
	a += b;
	if(a >= mod)
		a -= mod;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> m;
	dp[0][0][0] = 1;
	for(int i = 0; n > i; ++i)
	{
		for(int j = 0; k >= j; ++j)
		{
			for(int b = 0; (1 << m) > b; ++b)
			{
				int nowa = (((1 << m) - 1) & (b * 2));
				add(dp[i + 1][j][nowa], dp[i][j][b]);
				if(j != k)
				{
					add(dp[i + 1][j + 1][nowa + 1], ((ll) dp[i][j][b] * (1 + __builtin_popcount(b))) % mod);
				}
			}
		}
	}
	int sum = 0;
	for(int i = 0; (1 << m) > i; ++i)
		add(sum, dp[n][k][i]);
	cout << sum;
	
	
	
	return 0;
}