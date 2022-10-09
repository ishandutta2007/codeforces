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

using namespace std;

vector<pair<int, int> > sp[200000];

vector<int> days[200000];


int maxday = 0;

void construct(int t, int d, int c)
{
	int day = 0;
	for (int i = 0; i < sp[t].size(); i++)
	{
		if (sp[t][i].second != c)
		{
			day++;
			if (day == d)
				day++;
			days[day].push_back(sp[t][i].first);
			construct(sp[t][i].second, day, t);
			maxday = max(day, maxday);
		}
	}
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		sp[a - 1].push_back(make_pair(i + 1, b - 1));
		sp[b - 1].push_back(make_pair(i + 1, a - 1));
	}
	construct(0, 0, 0);
	printf("%d\n", maxday);
	for (int i = 1; i <= maxday; i++)
	{
		printf("%d ", days[i].size());
		for (int j = 0; j < days[i].size(); j++)
			printf("%d ", days[i][j]);
		printf("\n");
	}
}