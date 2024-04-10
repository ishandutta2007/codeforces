#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
const int MaxQ = 5e5 + 5;

int n, q, cnt = 1, ch[MaxN][26], fail[MaxN], pos[MaxN];
std::string s[MaxN];
std::vector<int> G[MaxN];
std::vector<std::array<int, 3>> Q[MaxN];
int ans[MaxQ], dfn[MaxN], size[MaxN], c[MaxN];

int main()
{
	std::cin >> n >> q;
	for(int i = 1; i <= n; ++i)
	{
		std::cin >> s[i];
		int u = 1;
		for(char c : s[i])
		{
			if(!ch[u][c - 'a']) ch[u][c - 'a'] = ++cnt;
			u = ch[u][c - 'a'];
		}
		pos[i] = u;
	}
	
	{
		std::queue<int> q;
		for(int c = 0; c < 26; ++c)
		if(ch[1][c]) fail[ch[1][c]] = 1, q.push(ch[1][c]);
		else ch[1][c] = 1;
		
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			for(int c = 0; c < 26; ++c)
			if(ch[u][c]) fail[ch[u][c]] = ch[fail[u]][c], q.push(ch[u][c]);
			else ch[u][c] = ch[fail[u]][c];
		}
		
		for(int i = 2; i <= cnt; ++i) G[fail[i]].push_back(i);
	}
	
	int dfs_clock = 0;
	auto dfs = [&](auto &&self, int u) -> void
	{
		dfn[u] = ++dfs_clock; size[u] = 1;
		for(int v : G[u]) self(self, v), size[u] += size[v];
	};
	dfs(dfs, 1);
	
	for(int i = 1, l, r, k; i <= q; ++i)
	{
		std::cin >> l >> r >> k;
		Q[l - 1].push_back({i, k, -1});
		Q[r].push_back({i, k, 1});
	}
	
	auto add = [&](int x) {for(; x <= cnt; x += (x & -x)) ++c[x];};
	auto sum = [&](int x) {int res = 0; for(; x; x -= (x & -x)) res += c[x]; return res;};
	
	for(int i = 1; i <= n; ++i)
	{
		int u = 1;
		for(char c : s[i]) add(dfn[u = ch[u][c - 'a']]);
		for(const auto &p : Q[i]) ans[p[0]] += (sum(dfn[pos[p[1]]] + size[pos[p[1]]] - 1) -
			sum(dfn[pos[p[1]]] - 1)) * p[2];
	}
	
	for(int i = 1; i <= q; ++i) std::cout << ans[i] << "\n";
	return 0;
}