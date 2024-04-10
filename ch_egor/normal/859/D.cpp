#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = (1 << 7);

int n;
int lgn;
int pr[MAX_N][MAX_N];
ld dp[MAX_N][MAX_N];
ld dp_pr[MAX_N][MAX_N];

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	scanf("%d", &n);

	lgn = n;
	n = (1 << n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &pr[i][j]);
		}
	}
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dp[i][j] = 0;
			dp_pr[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i)
		dp_pr[0][i] = 1;
	
	for (int sh = 1, lg = 1; sh < n; (sh <<= 1), ++lg)
	{
//		cout << "NOW " << sh << endl;
		for (int i = 0; i < n; i += (sh << 1))
		{
			for (int j = i; j < i + sh; ++j)
			{
				for (int k = i + sh; k < i + (sh << 1); ++k)
				{
					if (lg != 1)
					{
						dp[lg][j] = max(dp[lg][j],
										dp[lg - 1][j] + dp[lg - 1][k] +
										dp_pr[lg - 1][j] * (1 << (lg - 2)) +
										dp_pr[lg - 1][k] * (1 << (lg - 2)));
						dp[lg][k] = max(dp[lg][k],
										dp[lg - 1][j] + dp[lg - 1][k] +
										dp_pr[lg - 1][j] * (1 << (lg - 2)) +
										dp_pr[lg - 1][k] * (1 << (lg - 2)));
					}
					
					dp_pr[lg][j] += dp_pr[lg - 1][j] * dp_pr[lg - 1][k] * (pr[j][k] / 100.0);
					dp_pr[lg][k] += dp_pr[lg - 1][j] * dp_pr[lg - 1][k] * (pr[k][j] / 100.0);
				}
			}
		}

//		for (int i = 0; i < n; ++i)
//		{
//			cout << dp_pr[lg][i] << " ";
//		}
//		cout << endl;
//		for (int i = 0; i < n; ++i)
//		{
//			cout << dp[lg][i] << " ";
//		}
//		cout << endl;
	}
	
	ld ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, dp[lgn][i] + (1 << (lgn - 1)) * dp_pr[lgn][i]);

	cout << fixed << setprecision(20);
	cout << ans << "\n";
	
	return 0;
}