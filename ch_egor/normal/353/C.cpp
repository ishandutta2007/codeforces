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
int arr[228228];
char st[228228];
int64 sums[228228];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%s", st);

	for (int i = 1; i <= n; ++i)
	{
		sums[i] = sums[i - 1] + arr[i];
	}

	int64 answer = 0;
	for (int i = 0; i < n; ++i)
	{
		if (st[i] == '1') answer += arr[i + 1];
	}

	int64 prev = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		if (st[i] == '1')
		{
			answer = max(answer, prev + sums[i]);
			prev += arr[i + 1];
		}
	}

	printf("%lld", answer);

	fclose(stdin);
	fclose(stdout);

	return 0;
}