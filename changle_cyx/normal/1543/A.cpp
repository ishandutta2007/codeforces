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
//orzzlt
void work() {
	s64 a, b; 
	read(a), read(b); 

	if (a < b) swap(a, b); 
	s64 d = a - b; 

	if (d == 0) puts("0 0"); 
	else printf("%lld %lld\n", d, min(a % d, d - a % d)); 
}

int main() {
	int T; 
	read(T); 

	while (T--) work(); 

	return 0; 
}