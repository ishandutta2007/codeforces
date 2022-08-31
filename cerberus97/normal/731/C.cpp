#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

vector <int> g[N];
int a[N];
bool seen[N];

int bfs(int);

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 0; i < m; ++i)
	{
		int l, r;
		cin >> l >> r;
		g[l].push_back(r);
		g[r].push_back(l);
	}

	int ans = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (!seen[i])
		{
			ans += bfs(i);
			// cout << i << ' ' << ans << endl;
		}
	}

	cout << ans;
}

int bfs(int st)
{
	queue <int> q;
	map <int, int> m;
	int elems = 1;

	seen[st] = true;
	q.push(st);
	m[a[st]] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto &i : g[cur])
		{
			if (!seen[i])
			{
				seen[i] = true;
				q.push(i);
				
				if (m.find(a[i]) == m.end())
					m[a[i]] = 1;

				else
					m[a[i]] += 1;

				++elems;
			}
		}
	}

	int mx = 0;

	for (auto &i : m)
		mx = max(mx, i.second);

	return elems - mx;
}