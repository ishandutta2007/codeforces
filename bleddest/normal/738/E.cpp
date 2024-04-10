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

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, s;
	scanf("%d%d", &n, &s);
	vector<int> z(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &z[i]);
	--s;
	int ans = 0;
	if (z[s] > 0)
	{
		++ans;
		z[s] = 0;
	}
	vector<int> cnt(n);
	for (int i = 0; i < n; i++)
		cnt[z[i]]++;
	for (int i = 1; i < n && cnt[0] > 1; i++)
	{
		if (cnt[i] == 0)
		{
			ans++;
			cnt[i]++;
			cnt[0]--;
		}
	}
	int cr = 1e9;
	int change = 0;
	int curcnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (cnt[i])
			curcnt += cnt[i];
		else
		{
			curcnt++;
			change++;
		}
		cr = min(cr, change + max(0, n - curcnt));
	}

	printf("%d\n", cr + ans);
	return 0;
}