#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <iomanip>
//#include <ctime>
//#include <cmath>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int MAXN = 5000005;

int64 arr[5000005];
int64 dp[5000005];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 1; i < MAXN; ++i)
	{
		arr[i] = 0;
	}

	int k;
	int ans;

	for (int i = 2; i < MAXN; ++i)
	{
		if (arr[i] == 0)
		{
			for (int j = 1; i*j < MAXN; ++j)
			{
				arr[i*j] += 1;
				if (j%i == 0)
				{
					k = j;
					ans = 0;
					while (k%i == 0)
					{
						k /= i;
						++ans;
					}

					arr[i*j] += ans;
				}
			}
		}
	}

	dp[1] = 0;
	for (int i = 2; i < MAXN; ++i)
	{
		dp[i] = dp[i - 1] + arr[i];
	}

	int t;
	scanf("%d", &t);
	int a, b;
	for (int i = 0; i < t; ++i)
	{
		scanf("%d %d", &a, &b);
		printf("%I64d\n", dp[a] - dp[b]);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}