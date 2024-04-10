#include <bits/stdc++.h>

typedef long long s64; 

template <class T>
inline void read (T &x)
{
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

const int MaxN = 1e2 + 5; 

int n; 
int a[MaxN], ans[MaxN]; 

int main()
{
	read(n); 
	for (int i = 1; i <= n; ++i) read(a[i]); 
	std::sort(a + 1, a + n + 1); 
	
	int p = 0; 
	for (int i = 1; i <= n; ++i)
		if (i & 1) ans[++p] = a[i]; 
	for (int i = n; i >= 1; --i)
		if (~i & 1) ans[++p] = a[i]; 
		
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]); 
		
	return 0; 
}