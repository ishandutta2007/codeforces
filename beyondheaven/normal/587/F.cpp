#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
const int Size = 323;

int n, q, cnt = 1, ch[MaxN][26], fail[MaxN], pos[MaxN];
std::string s[MaxN];
int64_t ans[MaxN], tmp[MaxN];
std::vector<std::array<int, 3>> Q1[MaxN], Q2[MaxN];
std::vector<int> G[MaxN];
int dfn[MaxN], size[MaxN], sum[MaxN];
int bel[MaxN], val[MaxN], add[MaxN];

int main()
{
	std::cin >> n >> q;
	for(int i = 1; i <= n; ++i) std::cin >> s[i];
	for(int i = 1, l, r, k; i <= q; ++i)
	{
		std::cin >> l >> r >> k;
		if(int(s[k].size()) >= Size) Q1[k].push_back({i, l, r});
		else Q2[l - 1].push_back({i, k, -1}), Q2[r].push_back({i, k, 1});
	}
	
	auto trans = [&](int u, int c) {if(!ch[u][c]) ch[u][c] = ++cnt; return ch[u][c];};
	for(int i = 1; i <= n; ++i)
	{
		int u = 1;
		for(char c : s[i]) u = trans(u, c - 'a');
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
	}
	
	for(int i = 2; i <= cnt; ++i) G[fail[i]].push_back(i);
	
	int dfs_clock = 0;
	auto dfs = [&](auto &&self, int u) -> void
	{
		dfn[u] = ++dfs_clock; size[u] = 1;
		for(int v : G[u]) self(self, v), size[u] += size[v];
	};
	dfs(dfs, 1);
	
	std::vector<int> ord(cnt);
	std::iota(ord.begin(), ord.end(), 1);
	std::sort(ord.begin(), ord.end(), [&](int a, int b) {return dfn[a] > dfn[b];});
	
	for(int k = 1; k <= n; ++k) if(int(s[k].size()) >= Size)
	{
		std::fill(sum + 1, sum + cnt + 1, 0);
		std::fill(tmp + 1, tmp + n + 1, 0);
		int u = 1;
		for(char c : s[k]) ++sum[u = ch[u][c - 'a']];
		for(int i : ord) if(i > 1) sum[fail[i]] += sum[i];
		for(int i = 1; i <= n; ++i) tmp[i] = tmp[i - 1] + sum[pos[i]];
		for(const auto &p : Q1[k]) ans[p[0]] = tmp[p[2]] - tmp[p[1] - 1];
	}
	
	for(int i = 1; i <= cnt; ++i) bel[i] = (i - 1) / Size + 1;
	
	auto modify = [&](int l, int r)
	{
		if(bel[l] == bel[r]) for(int i = l; i <= r; ++i) ++val[i];
		else
		{
			for(int i = l; bel[i] == bel[l]; ++i) ++val[i];
			for(int i = r; bel[i] == bel[r]; --i) ++val[i];
			for(int i = bel[l] + 1; i < bel[r]; ++i) ++add[i];
		}
	};
	auto query = [&](int p) {return val[p] + add[bel[p]];};
	
	for(int i = 1; i <= n; ++i)
	{
		modify(dfn[pos[i]], dfn[pos[i]] + size[pos[i]] - 1);
		for(const auto &p : Q2[i])
		{
			int u = 1;
			for(char c : s[p[1]]) ans[p[0]] += query(dfn[u = ch[u][c - 'a']]) * p[2];
		}
	}
	
	for(int i = 1; i <= q; ++i) std::cout << ans[i] << "\n";
	return 0;
}