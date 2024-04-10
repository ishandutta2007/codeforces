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

const int MAX_N = 505;

int n, k;
int64 arr[MAX_N][MAX_N];
int64 answer = 0;
int64 have[MAX_N*MAX_N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> k;

	for (int i = 1; i <= n*n; ++i)
	{
		have[i] = i;
	}
	int l = 1, r = n*n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < k - 1; ++j)
		{
			arr[i][j] = have[l];
			++l;
		}
		for (int j = k - 1; j < n; ++j)
		{
			arr[i][j] = have[r];
			--r;
		}
		reverse(arr[i] + k - 1, arr[i] + n);
	}

	for (int i = 0; i < n; ++i)
	{
		answer += arr[i][k - 1];
	}

	printf("%I64d\n", answer);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%I64d ", arr[i][j]);
		}
		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}