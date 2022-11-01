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

int main()
{
	int w1, h1, w2, h2; 
	
	std::cin >> w1 >> h1 >> w2 >> h2; 
	
	std::cout << 2LL * (h1 + h2) + w1 * 2LL + 4;  
	
	return 0; 
}