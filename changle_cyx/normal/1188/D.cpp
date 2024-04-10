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
inline void relax(T &x, const T &y)
{
	if (x < y)
		x = y; 
}

template <class T>
inline void tense(T &x, const T &y)
{
	if (x > y)
		x = y; 
}

typedef long long s64; 

const int MaxLog = 65; 
const int MaxN = 1e5 + 5; 

const int INF = 0x3f3f3f3f; 

int n; 
s64 a[MaxN], b[MaxN], c[MaxN]; 
int f[MaxLog][MaxN]; 

int main()
{
//	freopen("equal.in", "r", stdin); 
//	freopen("equal.out", "w", stdout); 

	read(n); 

	s64 maxval = 0; 
	for (int i = 1; i <= n; ++i)
	{
		read(a[i]); 
		relax(maxval, a[i]); 
	}
	for (int i = 1; i <= n; ++i)
		a[i] = maxval - a[i]; 

	memset(f, 0x3f, sizeof(f)); 

	f[0][0] = 0; 
	for (int tk = 1; tk <= 63; ++tk)
	{
		int k = tk - 1, cnt0 = 0, cnt1 = 0, cntup = 0; 
		for (int i = 1; i <= n; ++i)
			if (a[i] >> k & 1)
				++cnt1; 
			else
				++cnt0; 

		for (int i = 0; i <= n; ++i)
		{
			if (i)
			{
				if (a[i] >> k & 1)
					--cnt1, ++cntup; 
				else
					--cnt0, ++cnt1; 
			}
			if (f[k][i] < INF)
			{
				tense(f[tk][cntup], f[k][i] + cnt1); 
				tense(f[tk][cntup + cnt1], f[k][i] + cnt0 + cntup); 
			}
		}

		cnt0 = cnt1 = 0; 
		for (int i = 1; i <= n; ++i)
			if (a[i] >> k & 1)
				b[++cnt1] = a[i]; 
			else
				c[++cnt0] = a[i]; 
		for (int i = 1; i <= cnt1; ++i)
			a[i] = b[i]; 
		for (int i = 1; i <= cnt0; ++i)
			a[i + cnt1] = c[i]; 
	}

	std::cout << f[63][0] << std::endl; 

	return 0; 
}