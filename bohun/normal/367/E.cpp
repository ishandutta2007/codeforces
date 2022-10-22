#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define up(i, n) for(int i = 0; n > i; ++i)
using namespace std;
const int nax = 405, mod = 1e9 + 7;
int n, m, x;
int dp[2][nax][nax];

void add(int &a, int b)
{
	a += b;
	if(a >= mod)
		a -= mod;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> x;
	if(n > m)
	{
		cout << 0;
		return 0;
	}
	dp[0][0][0] = 1;
	for(int i = 1; m >= i; ++i)
	{
		int ja = (i % 2);
		int on = ((i + 1) % 2);
		for(int j = 0; n >= j; ++j)
		{
			for(int ile = 0; n >= ile; ++ile)
			{
				dp[ja][j][ile] = 0;
				if(i != x)
				{
					// add
					if(j && ile)
					add(dp[ja][j][ile], dp[on][j - 1][ile - 1]);
					// nothing
					add(dp[ja][j][ile], dp[on][j][ile]);
					// end
					add(dp[ja][j][ile], dp[on][j + 1][ile]);
					// add && end
					if(ile)
					add(dp[ja][j][ile], dp[on][j][ile - 1]);
				}
				else
				{
					// add
					if(j && ile)
						add(dp[ja][j][ile], dp[on][j - 1][ile - 1]);
					// add && end
					if(ile)
						add(dp[ja][j][ile], dp[on][j][ile - 1]);
				}
			}
		}
	}
	int sil = 1;
	for(int i = 1; n >= i; ++i)
		sil = (ll) sil * i % mod;
	cout << (ll) sil * dp[(m % 2)][0][n] % mod;

    return 0;
}