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
const int nax = 1005, inf = 1000000000, mod = 1e9 + 7;
int n;
ll dp[2 * nax][2 * nax][2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	dp[2 * n][0][0] = dp[2 * n][0][1] = 0;
	for(int i = 2 * n - 1; i >= 0; --i)
	{
		for(int j = 0; 2 * n >= j; ++j)
		{
			if(i % 2 != j % 2 || j > 2 * n - i)
				continue;
			bool up = 0;
			bool down = 0;
			if(j + 1 <= 2 * n - i)
				up = 1;
			if(j)
				down = 1;
			dp[i][j][0] = (up ? max(dp[i + 1][j + 1][0], dp[i + 1][j + 1][1]) : 0) + (down ? max(dp[i + 1][j - 1][0], dp[i + 1][j - 1][1]) : 0); 
			dp[i][j][0] %= mod;
			int one = 0;
			int two = 0;
			if(up)
			{
				one = (1 + dp[i + 1][j + 1][0] + max((ll)0, max(dp[i + 1][j - 1][0], dp[i + 1][j - 1][1]))) % mod;
			}
			if(down)
			{
				two = (1 + dp[i + 1][j - 1][0] + max((ll)0, max(dp[i + 1][j + 1][0], dp[i + 1][j + 1][1]))) % mod;
			}
			dp[i][j][1] = max(one, two);
		}
	}
	cout << max(dp[0][0][0], dp[0][0][1]);
	
		
	return 0;
}