#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = (1 << 20) + 1234;
int tc;
int n, m, p[maxN];
void solve()
{
	cin >> n >> m;
	for (int i = 1; i < (1 << n); i++)
		cin >> p[i];
	vector<int> seq;
	priority_queue<pair<int, int>> q;
	q.push({p[1], 1});
	for (int i = 0; i < (1 << n) - (1 << m); i++)
	{
		while (true)
		{
			int x = q.top().second;
			int y = x;
			while (true)
			{
				if (2 * y >= (1 << n))
					break;
				if (p[2 * y] == 0 && p[2 * y + 1] == 0)
					break;
				if (p[2 * y] > p[2 * y + 1])
					y = 2 * y;
				else
					y = 2 * y + 1;
			}
			if (y < (1 << m))
			{
				q.pop();
				if (p[2 * x])
					q.push({p[2 * x], 2 * x});
				if (p[2 * x + 1])
					q.push({p[2 * x + 1], 2 * x + 1});
			}
			else
			{
				y = x;
				while (true)
				{
					if (2 * y >= (1 << n))
					{
						p[y] = 0;
						break;
					}
					if (p[2 * y] == 0 && p[2 * y + 1] == 0)
					{
						p[y] = 0;
						break;
					}
					if (p[2 * y] > p[2 * y + 1])
						p[y] = p[2 * y], y = 2 * y;
					else
						p[y] = p[2 * y + 1], y = 2 * y + 1;
				}
				seq.push_back(x);
				break;
			}
		}
	}
	i64 s = 0;
	for (int i = 1; i < (1 << m); i++)
		s += p[i];
	cout << s << "\n";
	for (auto x : seq)
		cout
			<< x << " ";
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		solve();
	}
}