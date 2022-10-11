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

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int n;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int64 x = 0;
	int64 y = 0;

	cin >> n;
	int64 gg;
	string st;

	bool good = true;
	for (int i = 0; i < n; ++i)
	{
		cin >> gg >> st;

		if (st == "North")
		{
			if (x - gg < 0)
			{
				printf("NO");
				return 0;
			}
			x -= gg;
		}
		else if (st == "South")
		{
			if (x + gg > 20000)
			{
				printf("NO");
				return 0;
			}
			x += gg;
		}
		else
		{
			if (x == 0 || x == 20000)
			{
				printf("NO");
				return 0;
			}
		}
	}

	if (x != 0)
	{
		printf("NO");
	}
	else
	{
		printf("YES");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}