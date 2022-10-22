#include <bits/stdc++.h>

using namespace std;

const int MAXP = 2000, MAXN = 105;

vector<int> tim(MAXN);
vector<pair<int, array<int, 4>>> item(MAXN);
int dp[MAXP + 5];
bool tb[MAXN][MAXP + 5];

int main()
{
	int n;
	scanf("%i", &n);
	for (int x = 0; x < n; x++)
	{
		int t, d, p;
		scanf("%i%i%i", &t, &d, &p);
		array<int, 4> arr = {t, d, p, x};
		tim[x] = t;
		item[x] = {d, arr};
	}
	sort(item.begin(), item.begin() + n);
	for (int x = 0; x < n; x++)
	{
		array<int, 4> arr = item[x].second;
		int t = arr[0], d = arr[1], p = arr[2], idx = arr[3];
		for (int y = d - 1; y >= t; y--)
		{
			if (dp[y] < dp[y - t] + p)
			{
				tb[x][y] = true;
				dp[y] = dp[y - t] + p;
			}
		}
	}
	int best = 0;
	for (int x = 0; x <= MAXP; x++)
		if (dp[x] > dp[best])
			best = x;
	printf("%i\n", dp[best]);
	int x = n - 1, y = best;
	vector<int> ans;
	while (y != 0)
	{
		while (!tb[x][y]) x--;
		array<int, 4> arr = item[x].second;
		int t = arr[0], d = arr[1], p = arr[2], idx = arr[3];
		ans.push_back(idx + 1);
		y -= t;
		x--;
	}
	reverse(ans.begin(), ans.end());
	printf("%i\n", ans.size());
	for (int x = 0; x < ans.size(); x++)
		printf("%i ", ans[x]);
	printf("\n");
}