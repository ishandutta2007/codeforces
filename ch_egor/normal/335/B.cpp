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

const int MAX_N = 50 * 1000 + 228;
const int ALPH = 26;

int n;
char st[MAX_N];
int cnt[ALPH];
int dp[100 * ALPH + 5][100 * ALPH + 5];
int type[100 * ALPH + 5][100 * ALPH + 5];

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	scanf("%s", st);
	n = strlen(st);

	if (n >= ALPH * 100)
	{
		for (int i = 0; i < n; ++i) ++cnt[(int)st[i] - 'a'];

		for (int i = 0; i < ALPH; ++i) if (cnt[i] >= 100)
		{
			printf("%s\n", string(100, i + 'a').c_str());
			return 0;
		}

		assert(false);
	}
	
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			if (j - i == 1) dp[i][j] = 1;
			else
			{
				if (st[i] == st[j - 1])
				{
					type[i][j] = 1;
					dp[i][j] = dp[i + 1][j - 1] + 2;
					if (i == j - 1) --dp[i][j];
				}
				if (dp[i][j - 1] >= dp[i][j])
				{
					type[i][j] = 2;
					dp[i][j] = dp[i][j - 1];
				}
				if (dp[i + 1][j] >= dp[i][j])
				{
					type[i][j] = 3;
					dp[i][j] = dp[i + 1][j];
				}
			}
		}
	}
	
	for (int i = 0; i < n; ++i) type[i][i + 1] = 1;

	int l = 0;
	int r = n;

	string ans = "";
	while (l < r && type[l][r] != 0)
	{
		if (type[l][r] == 1)
		{
			ans += st[l];
			++l;
			--r;
		}
		else if (type[l][r] == 2)
		{
			--r;
		}
		else if (type[l][r] == 3)
		{
			++l;
		}
	}

	for (int i = 0; i < (dp[0][n] >> 1); ++i)
	{
		ans += ans[(dp[0][n] >> 1) - i - 1];
	}
	
	if (ans.size() > 100)
	{
		if (ans.size() & 1)
		{
			ans = ans.substr(0, ans.size() / 2) + ans.substr(ans.size() / 2 + 1, ans.size() / 2);
		}

		assert(ans.size() % 2 == 0);

		while (ans.size() > 100)
		{
			ans = ans.substr(1, ans.size() - 2);
		}
	}

	printf("%s\n", ans.c_str());

	return 0;
}