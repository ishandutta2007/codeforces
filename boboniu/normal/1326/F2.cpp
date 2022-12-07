#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int k, n;
int g[20], c[20];
i64 cyc[20], dp[20][20], waypart[500], val[20], f[1234567];
vector<vector<int>> part;
unordered_map<i64, int> id;

mt19937_64 rnd(random_device{}());

void dfs(int sum, int pre, int num, i64 key)
{
	if (sum == 0)
	{
		id[key] = part.size();
		part.push_back(vector<int>(c, c + num));
	}
	for (int i = pre; i <= sum; i++)
	{
		c[num] = i;
		dfs(sum - i, i, num + 1, key + val[i]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		val[i] = rnd();
	dfs(n, 1, 0, 0);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			if (s[j] == '1')
				g[i] |= (1 << j);
		g[i] |= (1 << i);
	}
	int m = part.size();
	for (int i = 0; i < m; i++)
		waypart[i] = 0;
	for (int S = 0; S < (1 << n); S++)
	{
		int t = 0;
		cyc[0] = 0;
		for (int j = 0; j < n; j++)
			if (S & (1 << j))
			{
				c[t] = j;
				dp[0][t] = 1;
				cyc[0]++;
				t++;
			}
		for (int step = 1; step <= n; step++)
		{
			cyc[step] = 0;
			for (int p = 0; p < t; p++)
			{
				dp[step][p] = 0;
				for (int q = 0; q < t; q++)
					if (g[c[p]] & (1 << c[q]))
					{
						dp[step][p] += dp[step - 1][q];
					}
				cyc[step] += dp[step][p];
			}
		}
		int bs = (__builtin_parity(S) + n) % 2 ? -1 : 1;
		for (int i = 0; i < m; i++)
		{
			i64 s = bs;
			for (int x : part[i])
				s = s * cyc[x - 1];
			waypart[i] += s;
		}
	}
	for (int S = 0; S < (1 << (n - 1)); S++)
	{
		int seg = 1;
		i64 key = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (S & (1 << i))
				seg += 1;
			else
			{
				key += val[seg];
				seg = 1;
			}
		}
		key += val[seg];
		f[S] = waypart[id[key]];
	}
	for (int i = 0; i < n - 1; i++)
		for (int S = 0; S < (1 << (n - 1)); S++)
			if (S & (1 << i))
				f[S - (1 << i)] -= f[S];
	for (int S = 0; S < (1 << (n - 1)); S++)
	{
		cout << f[S] << " ";
	}
	cout << endl;
}