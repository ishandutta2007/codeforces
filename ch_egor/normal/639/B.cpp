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
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int n, d, h;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> d >> h;

	if (d > 2 * h || n - 1 < d || n - 1 < h || h > d)
	{
		printf("-1");
		return 0;
	}
	else
	{
		if (d == 1)
		{
			if (n != 2)
			{
				printf("-1");
				return 0;
			}
			else
			{
				printf("1 2");
			}
		}
		else
		{
			if (h == 1)
			{
				for (int i = 1; i <= h; ++i)
				{
					printf("%d %d\n", i, i + 1);
				}
				d -= h;
				for (int i = h + 1; i <= h + d; ++i)
				{
					if (i == h + 1)
					{
						printf("1 %d\n", i + 1);
					}
					else
					{
						printf("%d %d\n", i, i + 1);
					}
				}
				for (int i = h + d + 2; i <= n; ++i)
				{
					printf("%d %d\n", 1, i);
				}
			}
			else
			{
				for (int i = 1; i <= h; ++i)
				{
					printf("%d %d\n", i, i + 1);
				}
				d -= h;
				for (int i = h + 1; i <= h + d; ++i)
				{
					if (i == h + 1)
					{
						printf("1 %d\n", i + 1);
					}
					else
					{
						printf("%d %d\n", i, i + 1);
					}
				}
				for (int i = h + d + 2; i <= n; ++i)
				{
					printf("%d %d\n", 2, i);
				}
			}
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}