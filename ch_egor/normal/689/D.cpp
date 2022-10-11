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

const int INF = (1 << 30) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 200 * 1000 + 5;
const int MAX_LOG = 19;

int n;
int arr1[MAX_N];
int arr2[MAX_N];
int tree1[MAX_N * 4];
int tree2[MAX_N * 4];

int sp1[MAX_LOG][MAX_N];
int sp2[MAX_LOG][MAX_N];
int logs[MAX_N];

void build11()
{
	for (int i = 0; i < n; ++i)
	{
		sp1[0][i] = arr1[i];
	}

	for (int i = 1; i < MAX_LOG; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j + (1 << (i - 1)) < n) sp1[i][j] = max(sp1[i - 1][j], sp1[i - 1][j + (1 << (i - 1))]);
			else sp1[i][j] = sp1[i - 1][j];
		}
	}
}

void build22()
{
	for (int i = 0; i < n; ++i)
	{
		sp2[0][i] = arr2[i];
	}

	for (int i = 1; i < MAX_LOG; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j + (1 << (i - 1)) < n) sp2[i][j] = min(sp2[i - 1][j], sp2[i - 1][j + (1 << (i - 1))]);
			else sp2[i][j] = sp2[i - 1][j];
		}
	}
}

int get11(int a, int b, int c, int l, int r)
{
	int len = logs[r - l];

	return max(sp1[len][l], sp1[len][r - (1 << len)]);
}

int get22(int a, int b, int c, int l, int r)
{
	int len = logs[r - l];

	return min(sp2[len][l], sp2[len][r - (1 << len)]);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr1[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr2[i]);
	}

	build11();
	build22();

	logs[0] = logs[1] = 0;
	for (int i = 2; i <= n; ++i)
	{
		logs[i] = logs[i >> 1] + 1;
	}

	//build1(0, 0, n);
	//build2(0, 0, n);

	int l, r, m;
	int ptr1, ptr2;
	int64 answer = 0;

	for (int i = 0; i < n; ++i)
	{
		if (arr1[i] > arr2[i]) continue;
		if (get11(0, 0, n, i, n) < get22(0, 0, n, i, n)) continue;

		if (arr1[i] < arr2[i])
		{
			l = i;
			r = n;
			while (r - l > 1)
			{
				m = (l + r) >> 1;
				if (get11(0, 0, n, i, m + 1) < get22(0, 0, n, i, m + 1))
				{
					l = m;
				}
				else
				{
					r = m;
				}
			}
			ptr1 = l;
		}
		else
		{
			ptr1 = i - 1;
		}

		if (get11(0, 0, n, i, n) > get22(0, 0, n, i, n))
		{
			l = i - 1;
			r = n - 1;
			while (r - l > 1)
			{
				m = (l + r) >> 1;
				if (get11(0, 0, n, i, m + 1) > get22(0, 0, n, i, m + 1))
				{
					r = m;
				}
				else
				{
					l = m;
				}
			}
			ptr2 = r;
		}
		else
		{
			ptr2 = n;
		}

		answer += ptr2 - ptr1 - 1;
	}

	printf("%lld", answer);

	fclose(stdin);
	fclose(stdout);

	return 0;
}