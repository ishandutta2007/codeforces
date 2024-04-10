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

const int MaxN = 2e5 + 5; 

int h, n; 
int p[MaxN]; 

int main()
{
#ifdef orzczk
	freopen(".in", "r", stdin); 
#endif

	int T; 
	read(T); 
	while (T--)
	{
		read(h), read(n); 
		for (int i = 1; i <= n; ++i)
		{
			read(p[i]); 
		}

		int ans = 0; 
		for (int i = 1; i <= n; ++i)
		{
			if (i + 2 <= n && p[i + 1] - 1 > p[i + 2])
				++ans; 
			else if (i + 2 <= n && p[i + 1] - 1 == p[i + 2])
				++i; 
			else if (i + 1 == n && p[i + 1] <= 1)
				++i;  
			else if (i + 1 == n)
				++ans;  
		}

		printf("%d\n", ans); 
	}
	return 0; 
}