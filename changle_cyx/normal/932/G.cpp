#include <bits/stdc++.h>

const int base = 26; 
const int mod = 1e9 + 7; 
const int MaxN = 1e6 + 5; 

int n; 
char s[MaxN], t[MaxN]; 
int ans[MaxN]; 

namespace PAM
{
	int lst, cur_n, nT = 1; 

	int fir[MaxN], del[MaxN], f[MaxN]; 
	int trans[MaxN][base], len[MaxN], par[MaxN]; 

	inline void init()
	{
		len[1] = -1; 
		par[0] = par[1] = 1; 
	}

	inline int find(int x)
	{
		while (s[cur_n] != s[cur_n - len[x] - 1])
			x = par[x]; 
		return x; 
	}

	inline void extend(int ch)
	{
		++cur_n, ch -= 'a'; 
		int cur = find(lst); 
		if (!trans[cur][ch])
		{
			int x = ++nT; 
			par[x] = trans[find(par[cur])][ch]; 
			len[trans[cur][ch] = x] = len[cur] + 2; 

			del[x] = len[x] - len[par[x]]; 

			if (del[x] == del[par[x]])
				fir[x] = fir[par[x]]; 
			else
				fir[x] = x; 
		}
		lst = trans[cur][ch]; 
	}
}

inline void add(int &x, const int &y)
{
	x += y; 
	if (x >= mod)
		x -= mod; 
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
#endif

	scanf("%s", t + 1); 
	n = strlen(t + 1);

	int cur = 0; 
	for (int i = 1; i <= (n >> 1); ++i)
	{
		s[++cur] = t[i]; 
		s[++cur] = t[n - i + 1]; 
	}

	using namespace PAM; 

	init(); 

	ans[0] = 1; 
	for (int i = 1; i <= n; ++i)
	{
		extend(s[i]); 
		for (int x = lst; x; x = par[fir[x]])
		{
			f[x] = ans[i - len[fir[x]]]; 

			if (fir[x] != x)
				add(f[x], f[par[x]]); 
			if (~i & 1)
				add(ans[i], f[x]); 
		}
	}

	std::cout << ans[n] << std::endl; 

	return 0; 
}