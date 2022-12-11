#include <bits/stdc++.h>
const int MaxN = 1e6 + 5;
const int LEN = 1048576;

int cnt = 1, cur = 1, ch[MaxN][26], len[MaxN], link[MaxN], pos[MaxN];
std::vector<int> G[MaxN];
int fa[MaxN][20], dfn[MaxN], size[MaxN];
void insert(int c)
{
	int p = cur; len[cur = ++cnt] = len[p] + 1; pos[len[cur]] = cur;
	for(; p && !ch[p][c]; p = link[p]) ch[p][c] = cur;
	if(!p) return link[cur] = 1, void();
	int q = ch[p][c];
	if(len[q] == len[p] + 1) return link[cur] = q, void();
	int nq = ++cnt; len[nq] = len[p] + 1;
	memcpy(ch[nq], ch[q], sizeof(ch[nq]));
	for(; p && ch[p][c] == q; p = link[p]) ch[p][c] = nq;
	link[nq] = link[q]; link[cur] = link[q] = nq;
}

int S[LEN << 1];
void update(int x, int v)
{
	S[x += LEN] = v;
	for(x >>= 1; x; x >>= 1) S[x] = std::max(S[x << 1], S[x << 1 | 1]);
}

int query(int l, int r)
{
	int ans = 0;
	for(l += LEN - 1, r += LEN + 1; l ^ r ^ 1; l >>= 1, r >>= 1)
	{
		if((l & 1) ^ 1) ans = std::max(ans, S[l ^ 1]);
		if(r & 1) ans = std::max(ans, S[r ^ 1]);
	}
	return ans;
}

int n, dp[MaxN];
char str[MaxN];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> (str + 1);
	std::reverse(str + 1, str + n + 1);
	for(int i = 1; i <= n; ++i) insert(str[i] - 'a');
	
	for(int i = 2; i <= cnt; ++i) G[link[i]].push_back(i);
	
	int dfs_clock = 0;
	auto dfs = [&](auto self, int u) -> void
	{
		size[u] = 1; dfn[u] = ++dfs_clock;
		fa[u][0] = link[u];
		for(int i = 1; i < 20; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
		for(int v : G[u])
		{
			self(self, v);
			size[u] += size[v];
		}
	};
	dfs(dfs, 1);
	
	dp[1] = 1;
	for(int i = 2, j = 0; i <= n; ++i)
	{
		dp[i] = 1;
		for(int k = dp[i - 1] + 1; k > 1; --k)
		{
			if(i - k == j + 1) ++j, update(dfn[pos[j]], dp[j]);
			for(int u : { pos[i], pos[i - 1] })
			{
				for(int t = 20; t--; ) if(len[fa[u][t]] >= k - 1) u = fa[u][t];
				if(query(dfn[u], dfn[u] + size[u] - 1) >= k - 1) { dp[i] = k; goto _break; }
			}
		}
		_break: ;
	}
	
	std::cout << *std::max_element(dp + 1, dp + n + 1) << "\n";
	return 0;
}