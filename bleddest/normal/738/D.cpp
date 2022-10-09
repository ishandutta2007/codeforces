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
#include <cassert>

using namespace std;

const long long INFLL = 1e18;
const int INF = 1e9;


int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	string z;
	cin >> z;
	vector<pair<int, int> > f;
	for (int i = 0; i < n; i++)
	{
		if (z[i] == '0')
		{
			if (f.empty() || f.back().second != i - 1)
				f.push_back(make_pair(i, i));
			else
				f[f.size() - 1].second = i;
		}
	}
	int curcnt = 0;
	for (int i = 0; i < f.size(); i++)
		curcnt += (f[i].second - f[i].first + 1) / b;
	vector<int> ans;
	for (int i = 0; i < f.size() && curcnt >= a; i++)
	{
		while (curcnt >= a)
		{
			if (f[i].second - f[i].first + 1 < b)
				break;
			curcnt--;
			f[i].first += b;
			ans.push_back(f[i].first - 1);
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i] + 1);
	printf("\n");
	return 0;
}