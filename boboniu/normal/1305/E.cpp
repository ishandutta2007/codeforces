#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int check(vector<int> x)
{
	int n = x.size();
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				if (x[i] + x[j] == x[k])
				{
					ans += 1;
				}
	return ans;
}

int n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int p = 1; p <= n; p++)
	{
		int maxlen = 0;
		if (p % 2 == 0)
			maxlen = p / 2 * (p / 2 - 1);
		else
			maxlen = (p / 2) * (p / 2);
		if (maxlen >= m)
		{
			vector<int> x;
			for (int y = 1; y < p; y++)
				x.push_back(y);
			x.push_back(p + 2 * (maxlen - m));
			int d = 500000000;
			while (x.size() < n)
			{
				x.push_back(d);
				d += 20000;
			}
			//assert(check(x) == m);
			for (auto y : x)
				cout << y << " ";
			cout << endl;
			exit(0);
		}
	}
	cout << "-1\n";
}