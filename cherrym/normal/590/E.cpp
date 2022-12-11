#include <bits/stdc++.h>

const int N = 755, M = 1e7 + 5;

int n, go[M][2], mark[M], fail[M], ToT = 1, len, que[M],
mx[N], my[N], vis[N], T, fis[M];
std::vector<int> str[M];
char s[M];
bool G[N][N], ix[N], iy[N];

bool nealchen(int u)
{
	for (int v = 1; v <= n; v++)
		if (G[u][v] && vis[v] < T)
		{
			vis[v] = T;
			if (!my[v] || nealchen(my[v]))
				return mx[u] = v, my[v] = u, 1;
		}
	return 0;
}

void dfs(int u)
{
	if (ix[u]) return;
	ix[u] = 1;
	for (int v = 1; v <= n; ++v) if (G[u][v] && !iy[v])
		if (!iy[v]) iy[v] = 1, dfs(my[v]);
}

int main()
{
	std::cin >> n; int res = n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s + 1); int u = 1;
		int len = strlen(s + 1);
		for (int j = 1; j <= len; j++)
		{
			int c = s[j] - 'a';
			if (!go[u][c]) go[u][c] = ++ToT;
			u = go[u][c]; str[u].push_back(i);
		}
		mark[u] = i;
	}
	go[0][0] = go[0][1] = que[len = 1] = 1;
	for (int i = 1; i <= len; i++)
	{
		int u = que[i];
		for (int c = 0; c < 2; c++)
			if (!go[u][c]) go[u][c] = go[fail[u]][c];
			else
			{
				int v = go[u][c]; que[++len] = v;
				fail[v] = go[fail[u]][c];
				fis[v] = mark[v] ? mark[v] : fis[fail[v]];
			}
	}
	for (int u = 1; u <= ToT; u++)
		for (int i = 0; i < str[u].size(); i++)
		{
			if (fis[fail[u]]) G[fis[fail[u]]][str[u][i]] = 1;
			if (fis[u]) G[fis[u]][str[u][i]] = 1;
		}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++) if (G[i][k])
			for (int j = 1; j <= n; j++) if (G[k][j])
				G[i][j] = 1;
	for (int i = 1; i <= n; i++) G[i][i] = 0;
	for (int i = 1; i <= n; i++) if (T++, nealchen(i)) res--;
	std::cout << res << std::endl;
	for (int i = 1; i <= n; i++) if (!mx[i]) dfs(i);
	for (int i = 1; i <= n; i++) if (ix[i] && !iy[i]) printf("%d ", i);
	return puts(""), 0;
}