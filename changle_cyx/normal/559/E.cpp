#include <bits/stdc++.h>

template <class T>
inline void read(T &x)
{
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

template <class T>
inline void tense(T &x, const T &y)
{
	if (x > y)
		x = y; 
}

template <class T>
inline void relax(T &x, const T &y)
{
	if (x < y)
		x = y; 
}

const int MaxN = 3e2 + 5; 
const int MaxM = 1e3 + 5; 
const int INF = 0x3f3f3f3f; 

struct node
{
	int a, l; 
	inline void scan()
	{
		read(a), read(l); 
	}
	inline bool operator < (const node &rhs) const
	{
		return a < rhs.a; 
	}
}p[MaxN]; 

int n; 
int real[MaxM], m; 
int f[MaxN][MaxM], g[MaxN][MaxN]; 

int main()
{
	read(n); 
	for (int i = 1; i <= n; ++i)
		p[i].scan(); 
	std::sort(p + 1, p + n + 1); 

	for (int i = 1; i <= n; ++i)
	{
		real[++m] = p[i].a; 
		real[++m] = p[i].a - p[i].l; 
		real[++m] = p[i].a + p[i].l; 
	}

	std::sort(real + 1, real + m + 1); 
	m = std::unique(real + 1, real + m + 1) - real - 1; 

	for (int i = 1; i <= n; ++i)
		g[i + 1][i] = std::lower_bound(real + 1, real + m + 1, p[i].a) - real; 
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
		{
			int cur = std::lower_bound(real + 1, real + m + 1, p[j].a - p[j].l) - real; 
			tense(g[i][j] = g[i][j - 1], cur); 
		}

	int ans = 0; 
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			relax(f[i][j] = f[i - 1][j], f[i][j - 1]); 

			int lef = p[i].a - p[i].l; 
			if (real[j] >= lef)
			{
				if (real[j] <= p[i].a)
				{
					int cur = std::lower_bound(real + 1, real + m + 1, lef) - real; 
					relax(f[i][j], f[i - 1][cur] + real[j] - lef); 
				}
				else
				{
					for (int k = 1; k <= i; ++k)
						if (p[k].a + p[k].l >= real[j])
							relax(f[i][j], f[k - 1][g[k + 1][i]] + real[j] - real[g[k + 1][i]]); 
				}
			}

		//	printf("%d %d: %d\n", i, j, f[i][j]); 
			relax(ans, f[i][j]); 
		}

	std::cout << ans << std::endl; 

	return 0; 
}