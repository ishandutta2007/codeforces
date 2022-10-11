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

bool is_prime(int x)
{
	if (x == 2) return true;
	if (x % 2 == 0)
	{
		return false;
	}
	for (int i = 3; i * i <= x; i += 2)
	{
		if (x % i == 0) return false;
	}

	return true;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	for (int i = 2; i < n - 1; ++i)
	{
		if (!is_prime(i) && !is_prime(n - i))
		{
			printf("%d %d", i, n - i);
			return 0;
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}