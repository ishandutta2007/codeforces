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

	bool have = false;
	int s1 = 0, s2 = 0;

	scanf("%d", &n);

	int a, b;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &a, &b);
		s1 += a;
		s2 += b;
		if (a % 2 == 0 && b % 2 != 0) have = true;
		if (a % 2 != 0 && b % 2 == 0) have = true;
	}

	if (s1 % 2 == 0 && s2 % 2 == 0)
	{
		printf("0");
	}
	else if ((s1 % 2 == 0 && s2 % 2 != 0) || (s1 % 2 != 0 && s2 % 2 == 0))
	{
		printf("-1");
	}
	else
	{
		if (have)
		{
			printf("1");
		}
		else
		{
			printf("-1");
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}