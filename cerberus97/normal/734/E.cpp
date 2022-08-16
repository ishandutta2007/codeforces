#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

vector <int> g[N], g2[N];
int a[N], c[N], mp[N], dp[N][2] = {0}, dist[N], nxt = 0;
bool seen[N] = {0};

void connectComponents(int st, int cur=0)
{
	seen[st] = true;
	mp[st] = cur;
	c[cur] = a[st];

	for (auto &i : g[st])
	{
		if (!seen[i])
		{
			if (a[i] == a[st])
				connectComponents(i, cur);

			else
				connectComponents(i, ++nxt);
		}

		else if (a[i] != a[st])
		{
			g2[mp[i]].push_back(mp[st]);
			g2[mp[st]].push_back(mp[i]);
		}
	}
}

// void dfs(int st)
// {
// 	seen[st] = true;
// 	int b = 0, w = 0;

// 	for (auto &i : g2[st])
// 	{
// 		if (!seen[i])
// 		{
// 			dfs(i);
// 			b += dp[i][0];
// 			w += dp[i][1];
// 		}
// 	}

// 	if (c[st] == 0)
// 	{
// 		dp[st][0] = min(b, w+2);
// 		dp[st][1] = min(w+1, b+1);
// 	}

// 	else
// 	{
// 		dp[st][0] = min(b+1, w+1);
// 		dp[st][1] = min(w, b+2);
// 	}
// }

int getDiameter(int st, int n)
{
	for (int i = 0; i <= n; ++i)
		seen[i] = 0;

	dist[st] = 0;
	int mx = 0, mxi = st;

	queue <int> q;
	q.push(st);
	seen[st] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto &i : g2[cur])
		{
			if (!seen[i])
			{
				dist[i] = dist[cur]+1;
				seen[i] = true;
				q.push(i);

				if (dist[i] > mx)
				{
					mx = dist[i];
					mxi = i;
				}
			}
		}
	}

	int ans = 0;

	for (int i = 0; i <= n; ++i)
		seen[i] = 0;

	q.push(mxi);
	seen[mxi] = true;
	dist[mxi] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto &i : g2[cur])
		{
			if (!seen[i])
			{
				dist[i] = dist[cur]+1;
				seen[i] = true;
				q.push(i);

				if (dist[i] > ans)
				{
					ans = dist[i];
				}
			}
		}
	}

	return ans;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 0; i < n-1; ++i)
	{
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	connectComponents(1);
	
	// for (int i = 0; g2[i].size() != 0; ++i)
	// {
	// 	for (auto &j : g2[i])
	// 	{
	// 		cout << i << ' ' << j << ' ' << c[i] << ' ' << c[j] << endl;
	// 	}
	// }

	// int b = 0, w = 0;

	// for (int i = 1; i <= n; ++i)
	// {
	// 	if (!seen[i])
	// 	{
	// 		dfs(i);

	// 		if (a[i])
	// 			++w;

	// 		else
	// 			++b;
	// 	}
	// }

	// cout << min(w,b);

	// dfs(0);

	// cout << min(dp[0][0], dp[0][1]);

	cout << (getDiameter(0, n)+1)/2;
}