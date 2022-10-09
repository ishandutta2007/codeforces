#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <limits>
#include <fstream>
#include <algorithm>
#include <string>

long long power(long long n, long long k)
{
	if (k == 1)
		return n;
	else return power(n, k / 2) * power(n, (k + 1) / 2);
}

using namespace std;

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<pair<int, int> > row(n + 1);
	vector<pair<int, int> > col(m + 1);
	for (int i = 0; i < k; i++)
	{
		int t, c, num;
		scanf("%d %d %d", &t, &num, &c);
		if (t == 1)
			row[num] = make_pair(i + 1, c);
		else
			col[num] = make_pair(i + 1, c);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (row[i].first > col[j].first)
				printf("%d ", row[i].second);
			else
				printf("%d ", col[j].second);

		}
		printf("\n");
	}
	return 0;
}