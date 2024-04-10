//good = all - bad
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

typedef long long s64; 

const int MaxN = 3e5 + 5; 

int n, lst[MaxN]; 
char s[MaxN]; 

int main()
{
	scanf("%d%s", &n, s + 1); 

	s64 ans = 1LL * n * (n - 1) >> 1; 
	for (int i = 1; i <= n; ++i)
	{
		lst[i] = s[i] == s[i - 1] ? lst[i - 1] + 1 : 1; 
		if (lst[i] == 1 && i != 1)
			ans -= lst[i - lst[i]]; 
		if (lst[i] != 1 && lst[i] < i)
			--ans; 
	}

	std::cout << ans << std::endl; 

	return 0; 
}