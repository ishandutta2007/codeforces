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

using namespace std;

int n, m;

bool swp(vector<int> r, int x1, int y1, int x2, int y2)
{
	swap(r[x1], r[y1]);
	swap(r[x2], r[y2]);
	for (int i = 0; i < m; i++)
		if (r[i] != i)
			return false;
	return true;
}

bool can_row(const vector<int>& r, int x, int y)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			if (swp(r, i, j, x, y) || swp(r, x, y, i, j))
				return true;
	return false;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d %d", &n, &m);
	vector<vector<int> > a(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
			a[i][j]--;
		}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
		{
			bool can = true;
			for (int k = 0; k < n; k++)
				can &= can_row(a[k], i, j);
			if (can)
			{
				cout << "YES\n";
				return 0;
			}
		}
	cout << "NO\n";
	return 0;
}