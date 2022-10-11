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
int dp[1228228];
vector<int> lines;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%s", st);

	n = strlen(st);

	for (int l = 0, r = 0; l < n; l = r)
	{
		while (r < n && st[r] == st[l]) ++r;
		lines.push_back(r - l);
	}

	if (lines.size() == 1)
	{
		printf("1");
		return 0;
	}

	if (st[0] == st[n - 1] && lines.size() != 1)
	{
		lines[0] += lines.back();
		lines.pop_back();
	}

	//for (int i = 0; i < lines.size(); ++i)
	//{
	//	printf("%d ", lines[i]);
	//}

	int l = 0, r = lines.size() - 1;
	int ans = 0;

	while (l < r)
	{
		if (lines[l] >= 2)
		{
			l += 1;
			++ans;
		}
		else if (lines[r] >= 2)
		{
			r -= 1;
			++ans;
		}
		else
		{
			r -= 2;
			++ans;
		}
	}

	if (l == r && lines[l] != 1)
		++ans;

	printf("%d", max(ans, 1));

	fclose(stdin);
	fclose(stdout);

	return 0;
}