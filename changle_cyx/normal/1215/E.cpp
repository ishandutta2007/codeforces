#include <bits/stdc++.h>

template <class T>
inline void read(T &x)
{
	static char ch; 
	static bool opt; 
	while (!isdigit(ch = getchar()) && ch != '-'); 
	x = (opt = ch == '-') ? 0 : ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
	if (opt)
		x = ~x + 1; 
}

template <class T>
inline void putint(T x)
{
	static char buf[25], *tail = buf; 

	if (x < 0)
	{
		x = ~x + 1; 
		putchar('-'); 
	}

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
	if (x > y)
		x = y; 
}

typedef long long s64; 

const int MaxN = 4e5 + 5; 
const int MaxS = 1 << 20; 

int n, m = 20, a[MaxN]; 
int c[MaxN][22]; 
s64 s[MaxN][22]; 

int totpos; 
int pos[22]; 

std::vector<int> V[22]; 

s64 f[MaxS]; 
s64 tot[22][22]; 

int main()
{
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	memset(f, 0x3f, sizeof(f)); 

	read(n); 
	for (int i = 1; i <= n; ++i)
	{
		read(a[i]); 
		V[a[i]].push_back(i); 
		for (int j = 1; j <= m; ++j)
		{
			s[i][j] = s[i - 1][j] + (a[i] == j) * j; 
			c[i][j] = c[i - 1][j] + (a[i] == j); 
		}
	}

	for (int i = 1; i <= m; ++i)
		if (c[n][i])
			pos[++totpos] = i; 

	int all = (1 << totpos) - 1; 

	for (int t1 = 1; t1 <= totpos; ++t1)
		for (int t2 = 1; t2 <= totpos; ++t2)
		{
			int i = pos[t1], j = pos[t2]; 
			if (i == j) continue; 
			for (auto u : V[i])
			{
				tot[i][j] += c[u][j]; 
			}
		}

	f[0] = 0; 
	for (int s = 0; s < all; ++s)
	{
		std::vector<int> tmp(0); 
		for (int t = 1; t <= totpos; ++t)
			if (s >> t - 1 & 1)
				tmp.push_back(t);

		for (int t = 1; t <= totpos; ++t)
			if (~s >> t - 1 & 1)
			{
				s64 now = 0; 
				for (auto lst : tmp)
					now += tot[pos[lst]][pos[t]]; 
				tense(f[s | (1 << t - 1)], f[s] + now); 
			}
	}

	std::cout << f[all] << '\n';

	return 0; 
}