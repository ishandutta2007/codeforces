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

const int MAX_N = 3000 + 5;

int n;
int arr[MAX_N];
double80 dp[MAX_N*MAX_N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	int cnt_move = 0;
	for (int i = n - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]), ++cnt_move;
		}
	}

	if (cnt_move & 1) printf("%d.00000000000000000000\n", 1 + 4 * (cnt_move >> 1));
	else printf("%d.00000000000000000000\n", 4 * (cnt_move >> 1));


	fclose(stdin);
	fclose(stdout);

	return 0;
}