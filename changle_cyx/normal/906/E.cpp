#include <bits/stdc++.h>

template <class T>
inline void putint(T x)
{
	static char buf[15], *tail = buf; 
	if (!x)
		putchar('0'); 
	else
	{
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline void tense(T &x, const T &y)
{
	if (y < x)
		x = y;
}

const int base = 26; 
const int MaxN = 1e6 + 5; 
const int INF = 0x3f3f3f3f; 

struct node
{
	int val, frm; 
	node(){}
	node(int a, int b):
		val(a), frm(b) {}
	inline bool operator < (const node &rhs) const
	{
		return val < rhs.val; 
	}
	inline node operator + (const node &rhs) const
	{
		return node(val + rhs.val, rhs.frm); 
	}
}f[MaxN], g[MaxN]; 

int n, m; 
char s[MaxN], t1[MaxN], t2[MaxN]; 

namespace PAM
{
	int lst, cur_n, nT = 1; 

	int fir[MaxN], del[MaxN]; 
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
			g[x] = node(INF, 0); 
		}
		lst = trans[cur][ch]; 
	}
} 

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
#endif

	scanf("%s%s", t1 + 1, t2 + 1); 
	m = strlen(t1 + 1); 

	for (int i = 1; i <= m; ++i)
	{
		s[++n] = t1[i]; 
		s[++n] = t2[i]; 
	}

	using namespace PAM; 

	init(); 
	for (int i = 1; i <= n; ++i)
	{
		extend(s[i]); 
		f[i] = node(INF, 0); 
		for (int x = lst; x; x = par[fir[x]])
		{
			g[x] = f[i - len[fir[x]]] + node(1, i - len[fir[x]]); 
			if (x != fir[x])
				tense(g[x], g[par[x]]); 
			if (~i & 1)
				tense(f[i], g[x]); 
		}
		if ((~i & 1) && s[i] == s[i - 1])
			tense(f[i], f[i - 2] + node(0, i - 2)); 
	}

	if (f[n].val >= INF)
	{
		puts("-1"); 
		return 0; 
	}

	std::cout << f[n].val << '\n';
	for (int cur = n; cur; cur = f[cur].frm)
	{
		if (f[cur].frm + 2 < cur || s[cur] != s[cur - 1])
		{
			putint((f[cur].frm + 2) >> 1), putchar(' '); 
			putint(cur >> 1), putchar('\n'); 
		}
	}

	return 0; 
}