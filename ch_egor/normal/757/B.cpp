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

const int MAX_N = 228228;

int n;
int arr[MAX_N];
int cnt[MAX_N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		++cnt[arr[i]];
	}

	int ans = 1;
	int cur_ans = 0;
	for (int i = 2; i < MAX_N; ++i)
	{
		cur_ans = 0;
		for (int j = i; j < MAX_N; j += i)
		{
			cur_ans += cnt[j];
		}
		ans = max(ans, cur_ans);
	}

	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}