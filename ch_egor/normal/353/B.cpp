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
int arr[228];
int have1[228];

int gg1[228];
int gg2[228];

vector<int> pp1;
vector<int> pp2;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	bool have = false;

	scanf("%d", &n);

	for (int i = 0; i < 2*n; ++i)
	{
		scanf("%d", &arr[i]);
		++have1[arr[i]];
	}

	int cnt1 = 0, cnt2 = 0;
	for (int i = 10; i <= 99; ++i)
	{
		if (have1[i] == 0) continue;
		if (have1[i] >= 2)
		{
			gg2[i]++, gg1[i]++, have1[i] -= 2; continue;
			++cnt1;
			++cnt2;
		}
		if (cnt1 < cnt2)
		{
			++cnt1;
			++gg1[i];
			have1[i]--;
		}
		else
		{
			++gg2[i];
			have1[i]--;
			++cnt2;
		}
	}

	for (int i = 10; i <= 99; ++i)
	{
		while (have1[i])
		{
			if (cnt1 < cnt2)
			{
				++cnt1;
				++gg1[i];
				have1[i]--;
			}
			else
			{
				++gg2[i];
				have1[i]--;
				++cnt2;
			}
		}
	}

	for (int i = 10; i <= 99; ++i)
	{
		for (int j = 0; j < 2 * n; ++j)
		{
			if (gg1[i] == 0) break;
			if (arr[j] == i) arr[j] = -1, pp1.push_back(i), --gg1[i];
		}
	}

	for (int i = 0; i < 2 * n; ++i)
	{
		if (arr[i] != -1)
		{
			pp2.push_back(arr[i]);
		}
	}

	set<int> gg;
	for (int i = 0; i < pp1.size(); ++i)
	{
		for (int j = 0; j < pp2.size(); ++j)
		{
			gg.insert(pp1[i] * 100 + pp2[j]);
		}
	}

	printf("%d\n", gg.size());
	for (int i = 0; i < 2*n; ++i)
	{
		printf("%d ", arr[i] == -1 ? 1 : 2);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}