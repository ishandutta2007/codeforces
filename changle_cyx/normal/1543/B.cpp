#include <bits/stdc++.h>

using namespace std; 

typedef long long s64; 

template <class T>
inline void read(T &x) {
	static char ch; 
	static bool opt; 
	while (!isdigit(ch = getchar()) && ch != '-'); 
	x = (opt = ch == '-') ? 0 : ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
	if (opt) x = ~x + 1; 
}

const int MaxN = 2e5 + 5; 

int n, a[MaxN]; 

void work() {
	read(n); 

	s64 sum = 0; 
	for (int i = 1; i <= n; ++i) read(a[i]), sum += a[i]; 

	printf("%lld\n", 1LL * (sum % n) * (n - sum % n)); 
}

int main() {
	int T; 
	read(T); 

	while (T--) work(); 
//orzzlt
	return 0; 
}