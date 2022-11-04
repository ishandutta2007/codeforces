#include <bits/stdc++.h>

using namespace std;

int dp[(int)(1 << 12) + 10], add[(int)(1 << 12) + 10];
int mas[30][2010], used[2010];
pair<int, int> arr[2010];

void solve()
{
	int n, m;
	cin >> n >> m;
	fill(used, used + m, 0);
	fill(dp, dp + (1 << n), 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mas[i][j];
			mas[i + n][j] = mas[i][j];	
		}
	}
	for (int j = 0; j < m; j++)
	{
		int mx = 0;
		for (int i = 0; i < n; i++)
			mx = max(mx, mas[i][j]);
		arr[j] = {mx, j};
	}
	sort(arr, arr + m);
	reverse(arr, arr + m);
	for (int i = 0; i < min(n, m); i++)
		used[arr[i].second] = 1;
	for (int j = 0; j < m; j++)
	{
		if (used[j])
		{
		fill(add, add + (1 << n), 0);
		for (int mask = 1; mask < (1 << n); mask++)
		{
			if ((mask & 1) == 0)
			{
				add[mask] = add[mask / 2];
				continue;
			}
			for (int i = 0; i < n; i++)
			{
				int sum = 0;
				for (int q = 0; q < n; q++)
					if (mask & (1 << q))
						sum += mas[i + q][j];
				add[mask] = max(add[mask], sum);
			}
		}
		for (int mask = (1 << n) - 1; mask > 0; mask--)
		{
			int cur = mask;
			while (cur > 0)
			{
				dp[mask] = max(dp[mask], add[cur] + dp[mask - cur]);
				cur = (mask & (cur - 1));
			}
		}
		}
	}
	cout << dp[(1 << n) - 1] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    	solve();
    return 0;
}