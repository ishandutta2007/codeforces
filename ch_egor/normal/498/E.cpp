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

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAX_H = 7;

int64 dp[1 << MAX_H][1 << MAX_H];
int64 add[1 << MAX_H][1 << MAX_H];
int64 buff[1 << MAX_H][1 << MAX_H];

void mult(int64 a[1 << MAX_H][1 << MAX_H], int64 b[1 << MAX_H][1 << MAX_H], int64 out[1 << MAX_H][1 << MAX_H], int h)
{
	for (int i = 0; i < (1 << h); ++i)
	{
		for (int j = 0; j < (1 << h); ++j)
		{
			buff[i][j] = 0;
			for (int k = 0; k < (1 << h); ++k)
			{
				buff[i][j] += a[i][k] * b[k][j];
				buff[i][j] %= MOD;
			}
		}
	}

	for (int i = 0; i < (1 << h); ++i)
	{
		for (int j = 0; j < (1 << h); ++j)
		{
			out[i][j] = buff[i][j];
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 0; i < (1 << MAX_H); ++i)
	{
		dp[i][i] = 1;
	}

	int n;
	for (int h = 0; h < MAX_H; ++h)
	{
		scanf("%d", &n);

		for (int i = 0; i < (1 << (h + 1)); ++i)
		{
			for (int j = 0; j < (1 << (h + 1)); ++j)
			{
				add[i][j] = 0;
				for (int k = 0; k < (1 << h); ++k)
				{
					add[i][j] += ((i | j | k | (k << 1)) == ((1 << (h + 1)) - 1));
				}
			}
		}

		while (n != 0)
		{
			if (n & 1)
			{
				mult(dp, add, dp, h + 1);
				--n;
			}

			mult(add, add, add, h + 1);
			n >>= 1;
		}
	}

	printf("%I64d", dp[0][0]);

	fclose(stdin);
	fclose(stdout);

	return 0;
}