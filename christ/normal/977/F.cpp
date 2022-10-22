#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<int> arr(MAXN);
map<int, int> dp;

int main()
{
	int n;
	scanf("%i", &n);
	for (int x = 1; x <= n; x++)
	{
		scanf("%i", &arr[x]);
		dp[arr[x]] = max(dp[arr[x]], dp[arr[x] - 1] + 1);
	}
	int ans = 0, endp;
	for (auto &x : dp)
	{
		if (x.second > ans)
		{
			ans = x.second;
			endp = x.first;
		}
	}
	printf("%i\n", ans);
	vector<int> idx;
	for (int x = n, y = endp; x > 0; x--)
	{
		if (arr[x] == y)
		{
			idx.push_back(x);
			y--;
		}
	}
	for (int x = idx.size() - 1; x >= 0; x--)
		printf("%i ", idx[x]);
	printf("\n");
}