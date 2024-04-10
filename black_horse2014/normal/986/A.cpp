/*
Examples
inputCopy
5 5 4 3
1 2 4 3 2
1 2
2 3
3 4
4 1
4 5
outputCopy
2 2 2 2 3 
inputCopy
7 6 3 2
1 2 3 3 2 2 1
1 2
2 3
3 4
2 5
5 6
6 7
outputCopy
1 1 1 2 2 1 1 
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000;
const int maxk = 100;

const int inf = 0x7f7f7f7f;

int n, m, k, s;
int a[maxn];
vector<int> E[maxn];
int f[maxn][maxk];

void bfs(const int & c)
{
	int i;
	queue<int> que;
	int u, v;

	for (i = 0; i < n; ++ i)
	{
		if (a[i] == c)
		{
			f[i][c] = 0;
			que.push(i);
		}
	}

	for (; !que.empty(); que.pop())
	{
		u = que.front();

		for (i = 0; i < E[u].size(); ++ i)
		{
			v = E[u][i];

			if (f[v][c] > f[u][c] + 1)
			{
				f[v][c] = f[u][c] + 1;
				que.push(v);
			}
		}
	}
}

int main(void)
{
	int i;
	int u, v;

	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k >> s;
	for (i = 0; i < n; ++ i)
	{
		cin >> a[i];
		-- a[i];
	}
	for (i = 0; i < m; ++ i)
	{
		cin >> u >> v;
		-- u;
		-- v;

		E[u].push_back(v);
		E[v].push_back(u);
	}

	for (i = 0; i < n; ++ i)
		memset(f[i], inf, sizeof(f[i][0]) * k);
	for (i = 0; i < k; ++ i)
		bfs(i);
	for (i = 0; i < n; ++ i)
	{
		if (i > 0)
			cout << " ";

		sort(f[i], f[i] + k);
		cout << accumulate(f[i], f[i] + s, 0);
	}
	cout << endl;

	return 0;
}