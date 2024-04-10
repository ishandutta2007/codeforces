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

int64 gcd(int64 a, int64 b)
{
	return b ? gcd(b, a % b) : a;
}

int64 f(int64 x)
{
	if (x == 1) return 1;
	int64 answer = 0;
	for (int64 i = 1; i < x; ++i)
	{
		if (gcd(i, x - i) == 1)
		{
			++answer;
		}
	}
	return answer;
}

int64 g(int64 x)
{
	int64 answer = 0;
	for (int64 i = 1; i * i <= x; ++i)
	{
		if (x % i == 0)
		{
			answer += f(i);
			if (i * i != x)
			{
				answer += f(x / i);
			}
		}
	}
	return answer;
}

int64 ff(int64 n)
{
	int64 result = n;
	for (int64 i = 2; i*i <= n; ++i)
	if (n % i == 0)
	{
		while (n % i == 0)
			n /= i;
		result -= result / i;
	}
	if (n > 1)
		result -= result / n;
	return result;
}

int64 gg(int64 x)
{
	return x - 1;
}

int64 n, k;



int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%lld%lld", &n, &k);


	if (k == 1)
	{
		cout << ff(n) % MOD;
	}
	else
	{
		k = (k + 1) / 2;
		int64 res = n;
		while (res != 1 && k != 0)
		{
			res = ff(res);
			--k;
		}
		cout << res % MOD;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}