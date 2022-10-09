#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <deque>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const long long INFLL = 1e18;
const int INF = 1e9;

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<int> > a(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int pref = 0;
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0)
				ans += (pref > 0);
			else
				pref++;
		}
		int suff = 0;
		for (int j = m - 1; j >= 0; j--)
		{
			if (a[i][j] == 0)
				ans += (suff > 0);
			else
				suff++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int pref = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j][i] == 0)
				ans += (pref > 0);
			else
				pref++;
		}
		int suff = 0;
		for (int j = n - 1; j >= 0; j--)
		{
			if (a[j][i] == 0)
				ans += (suff > 0);
			else
				suff++;
		}
	}
	printf("%d\n", ans);
	return 0;
}