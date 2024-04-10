#include <bits/stdc++.h>

using namespace std; 

typedef long long s64; 

void work() {
	int n, x, t; 
	scanf("%d%d%d", &n, &x, &t); 

	int d = t / x, p = min(d, n - 1); 
	s64 ans = 1LL * p * (p + 1) / 2 + 1LL * max(n - 1 - d, 0) * d; 

	printf("%lld\n", ans); 
}

int main() {
	int T; 
	scanf("%d", &T); 
	while (T--) work(); 
	return 0; 
}