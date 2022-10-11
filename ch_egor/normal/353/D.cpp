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
int arr[1228228];
char st[1228228];
int64 sums[1228228];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%s", st);

	n = strlen(st);
	reverse(st, st + n);


	int gg = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (st[i] == 'F')
		{
			++gg;
		}
		else if (gg > 0)
		{
			ans = max(ans + 1, gg);
		}
	}

	cout << ans;

	return 0;
	int cur = -1;
	for (int i = 0; i < n; ++i)
	{
		if (st[i] == 'F')
		{
			cur = i; break;
		}
	}

	if (cur == -1)
	{
		printf("0");
		return 0;
	}

	int cur2 = -1;
	for (int i = n - 1; i >= 0; --i)
	{
		if (st[i] != 'F')
		{
			cur2 = i;
			break;
		}
	}

	int cnt1 = 0;
	for (int i = cur; i <= cur2; ++i)
	{
		cnt1 += (st[i] == 'F');
	}

	int answer_time = 0;
	int last_size = 0;
	int prev_sz = 0;
	int cur_sz;
	int at_least_time = 0;
	int add = 0;
	answer_time = cur2 - cur - cnt1 + 1;
	for (int l = cur, r = 0; l < cur2; l = r)
	{
		while (r < cur2 && st[r] == st[l])
		{
			++r;
		}
		cur_sz = r - l;
		//cout << l << " " << r << endl;

		if (st[l] == 'F')
		{
			if (l - cur - 1 + at_least_time < cur_sz - 1)
				at_least_time = max(cur_sz - 1, at_least_time);
		}
		else
		{
			prev_sz += cur_sz;
		}
	}


	printf("%d", at_least_time + answer_time);

	fclose(stdin);
	fclose(stdout);

	return 0;
}