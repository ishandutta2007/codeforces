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

const int MAX_N = 1000 * 100 + 5;

int n;
int arr[MAX_N];
int64 answer = 0;

int64 my_abs(int64 x)
{
	return ((x > 0) ? x : -x);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	int x;
	int cnt0 = 0;
	for (int i = 0; i < 2*n; ++i)
	{
		scanf("%d.%d", &x, &arr[i]);
		cnt0 += (arr[i] == 0);
	}

	for (int i = 0; i < 2*n; ++i) answer += arr[i];

	if (cnt0 > n)
	{
		int64 best = LLINF;
		for (int i = cnt0 - n; i <= n; ++i)
		{
			best = min(best, my_abs(answer - 1000 * n + 1000 * i));
		}
		answer = best;
	}
	else
	{
		int64 best = LLINF;
		for (int i = 0; i <= cnt0; ++i)
		{
			best = min(best, my_abs(answer - 1000*n + 1000*i));
		}
		answer = best;
	}

	answer = my_abs(answer);

	printf("%lld.%03lld\n", answer / 1000, answer % 1000);


	fclose(stdin);
	fclose(stdout);

	return 0;
}