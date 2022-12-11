#include <bits/stdc++.h>
const int MaxN = 1e6 + 5;

int n, ans, pos[MaxN], vis[MaxN];
std::string s[MaxN];
int cnt, ch[MaxN][26], fail[MaxN], last[MaxN], dfn[MaxN], size[MaxN];
std::vector<int> G[MaxN];

int c[MaxN];
void add(int x, int v) {for(; x <= int(1e6); x += (x & -x)) c[x] += v;}
int sum(int x) {int res = 0; for(; x; x -= (x & -x)) res += c[x]; return res;}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		std::cin >> s[i];
		int u = 0;
		for(char x : s[i])
		{
			int c = x - 'a';
			if(!ch[u][c]) ch[u][c] = ++cnt;
			u = ch[u][c];
		}
		pos[i] = u; last[u] = i;
	}
	
	std::queue<int> q;
	for(int c = 0; c < 26; ++c) if(ch[0][c]) q.push(ch[0][c]);
	
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int c = 0; c < 26; ++c)
		if(ch[u][c]) q.push(ch[u][c]), fail[ch[u][c]] = ch[fail[u]][c];
		else ch[u][c] = ch[fail[u]][c];
		
		if(!last[u]) last[u] = last[fail[u]];
		G[fail[u]].push_back(u);
	}
	
	int dfs_clock = 0;
	auto dfs = [&](auto &&self, int u) -> void
	{
		size[u] = 1; dfn[u] = ++dfs_clock;
		for(int v : G[u]) self(self, v), size[u] += size[v];
	};
	dfs(dfs, 0);
	
	for(int i = 1; i <= n; ++i)
	{
		int u = 0;
		std::vector<int> V, S;
		for(char x : s[i])
		{
			u = ch[u][x - 'a'];
			add(dfn[u], 1);
			V.push_back(u);
		}
		
		int mn = 1e9;
		for(int j = V.size() - 1; j >= 0; --j)
		{
			int p = (j == int(V.size()) - 1 ? last[fail[V[j]]] : last[V[j]]);
			if(!p) continue;
			int t = (j + 1) - s[p].size() + 1;
			if(t < mn) mn = t, ++vis[p], S.push_back(p);
		}
		
		for(int p : S)
		ans += (vis[p] == sum(dfn[pos[p]] + size[pos[p]] - 1) - sum(dfn[pos[p]] - 1)), vis[p] = 0;
		
		for(int u : V) add(dfn[u], -1);
	}
	
	std::cout << ans << "\n";
	return 0;
}