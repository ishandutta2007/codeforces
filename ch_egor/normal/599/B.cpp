#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 2000 * 100 + 5;

int n, m;
int arr[MAX_N];
int f[MAX_N];
int cnt[MAX_N];
int dp[MAX_N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);

	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &f[i]);
		++cnt[f[i]];
		dp[f[i]] = i;
	}

	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= m; ++i)
	{
		if (cnt[arr[i]] == 0)
		{
			printf("Impossible");
			return 0;
		}
	}

	for (int i = 1; i <= m; ++i)
	{
		if (cnt[arr[i]] > 1)
		{
			printf("Ambiguity");
			return 0;
		}
	}

	printf("Possible\n");
	for (int i = 1; i <= m; ++i)
	{
		printf("%d ", dp[arr[i]]);
	}



	fclose(stdin);
	fclose(stdout);

	return 0;
}