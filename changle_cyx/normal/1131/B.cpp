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

const int MaxN = 1e4 + 5; 

int n, a[MaxN], b[MaxN];
 
int main()
{
	read(n); 
	
	using namespace std; 
	
	int now = 0, res = 0;
	
	a[0] = b[0] = -1;  
	for (int i = 1; i <= n; ++i)
	{
		read(a[i]), read(b[i]); 
		
		if (a[i] == a[i - 1] && b[i] == b[i - 1]) continue; 
		if (a[i] == a[i - 1])
			res += b[i - 1] < a[i] && b[i] >= a[i]; 
		else if (b[i] == b[i - 1])
			res += a[i - 1] < b[i] && a[i] >= b[i]; 
		else
			res += max(0, min(a[i], b[i]) - max(a[i - 1], b[i - 1]) + (a[i - 1] != b[i - 1])); 
	}
	
	std::cout << res; 
	return 0; 
}