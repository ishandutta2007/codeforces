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

int64 n, m, b, mod;
int64 arr[505];

int64 answer = 0;

int64 d[505][505];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%I64d %I64d %I64d %I64d", &n, &m, &b, &mod);

	for (int i = 1; i <= n; ++i)
	{
		scanf("%I64d", &arr[i]);
	}

	for (int i = 0; i < 505; ++i)
	{
		for (int j = 0; j < 505; ++j)
		{
			d[i][j] = 0;
		}
	}

	d[0][0] = 1;

	for (int k = 1; k <= n; ++k)
	{
		for (int i = 0; i <= m; ++i)
		{
			for (int j = 0; j <= b; ++j)
			{
				if (j + arr[k] <= b)
				{
					d[i + 1][j + arr[k]] += d[i][j];
					d[i + 1][j + arr[k]] %= mod;
				}
			}
		}
	}

	answer = 0;
	for (int i = 0; i <= b; ++i)
	{
		answer += d[m][i];
		answer %= mod;
	}

	printf("%I64d", answer);

	fclose(stdin);
	fclose(stdout);

	return 0;
}