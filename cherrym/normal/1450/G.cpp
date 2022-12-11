#include <bits/stdc++.h>

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 5005, E = 22, C = (1 << 20) + 5;

int n, a, b, m, bel[300], l[E], r[E], sze[E], tot, o[E], st[E], cnt, w;
bool is[300], f[C], g[C], h[C], fl[E];
char s[N], ch[E];

int main()
{
	std::cin >> n >> a >> b;
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) is[s[i]] = 1;
	for (char c = 'a'; c <= 'z'; c++) if (is[c]) ch[bel[c] = ++m] = c;
	for (int i = 1; i <= n; i++) r[bel[s[i]]] = i, sze[bel[s[i]]]++;
	for (int i = n; i >= 1; i--) l[bel[s[i]]] = i;
	f[0] = g[0] = 1;
	for (int S = 1; S < (1 << m); S++)
	{
		tot = w = 0;
		for (int i = 1; i <= m; i++)
			if ((S >> i - 1) & 1) o[++tot] = i,
				f[S] |= g[S ^ (1 << i - 1)];
		std::sort(o + 1, o + tot + 1, [&](int x, int y)
			{return r[x] < r[y];});
		int lt = 9973, rt = -9973, sum = 0;
		for (int i = tot, mn = 9973; i >= 1; i--)
		{
			if (r[o[i]] < mn) st[++w] = 1 << o[i] - 1;
			else st[w] |= 1 << o[i] - 1;
			mn = Min(mn, l[o[i]]);
			lt = Min(lt, l[o[i]]); rt = Max(rt, r[o[i]]);
			sum += sze[o[i]];
		}
		h[S] = a * (rt - lt + 1) <= sum * b; fl[0] = 1;
		for (int i = 1; i <= w; i++)
		{
			fl[i] = 0;
			for (int j = i, t = st[i]; j >= 1; j--, t |= st[j])
				if (fl[j - 1] && f[t] && h[t])
					{fl[i] = 1; break;}
		}
		g[S] = fl[w];
	}
	for (int c = 1; c <= m; c++) if (g[(1 << m) - 1 ^ (1 << c - 1)]) cnt++;
	std::cout << cnt << " ";
	for (int c = 1; c <= m; c++)
		if (g[(1 << m) - 1 ^ (1 << c - 1)])
			putchar(ch[c]), putchar(' ');
	return puts(""), 0;
}