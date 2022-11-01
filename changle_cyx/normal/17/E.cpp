#include <bits/stdc++.h>

typedef long long s64; 

const int base = 26; 
const int MaxN = 2e6 + 5; 
const int mod = 51123987; 

int n, ans; 
int cnt[2][MaxN]; 

inline void add(int &x, const int &y)
{
	x += y; 
	if (x >= mod)
		x -= mod; 
}

inline void dec(int &x, const int &y)
{
	x -= y; 
	if (x < 0)
		x += mod; 
}

namespace PAM
{
	int lst, nT = 1, cur_n; 
	int len[MaxN], par[MaxN], dep[MaxN]; 

	char s[MaxN]; 
	int ect, adj[MaxN], nxt[MaxN], to[MaxN], code[MaxN]; 

	inline void init()
	{
		ect = 0; 
		for (int i = 0; i <= nT; ++i)
			adj[i] = 0; 

		cur_n = 0; 
		len[nT = 1] = -1; 
		par[0] = par[1] = 1; 
	}

	inline int find(int x)
	{
		while (s[cur_n] != s[cur_n - len[x] - 1])
			x = par[x]; 
		return x; 
	}

	inline int trans(int x, int ch)
	{
		for (int e = adj[x]; e; e = nxt[e])
			if (code[e] == ch)
				return to[e]; 
		return 0; 
	}

	inline void insert(int x, int y, int ch)
	{
		nxt[++ect] = adj[x]; 
		adj[x] = ect; 
		to[ect] = y; 
		code[ect] = ch; 
	}

	inline void extend(int ch, int opt)
	{
		s[++cur_n] = ch, ch -= 'a'; 
		int cur = find(lst);  
		if (!trans(cur, ch))
		{
			int x = ++nT; 
			par[x] = trans(find(par[cur]), ch); 

			dep[x] = dep[par[x]] + 1; 
			len[x] = len[cur] + 2; 

			insert(cur, x, ch); 
		}

		lst = trans(cur, ch); 

		if (!opt)
		{
			add(ans, dep[lst]); 
			add(cnt[opt][cur_n] = cnt[opt][cur_n - 1], dep[lst]); 
		}
		else
			cnt[opt][n - cur_n + 1] = dep[lst]; 
	}
}

char str[MaxN]; 

int main()
{
	using namespace PAM; 

	scanf("%d%s", &n, str + 1); 
	
	init(); 
	for (int i = 1; i <= n; ++i)
		extend(str[i], 0); 
	init(); 
	for (int i = n; i >= 1; --i)
		extend(str[i], 1); 

	ans = (1LL * ans * (ans - 1) >> 1) % mod; 

	for (int i = 1; i < n; ++i)
		dec(ans, 1LL * cnt[0][i] * cnt[1][i + 1] % mod); 

	std::cout << ans << std::endl; 

	return 0; 
}