#include <bits/stdc++.h>

typedef long long s64; 

const int MaxN = 100000 + 5; 

int n, Q; 
char s[MaxN]; 

s64 a[MaxN]; 

int main() {
	scanf("%d%d", &n, &Q); 
	scanf("%s", s + 1); 

	for (int i = 1; i <= n; ++i) a[i] = a[i - 1] + (s[i] - 'a' + 1); 

	while (Q--) {
		int l, r; 
		scanf("%d%d", &l, &r); 
		printf("%lld\n", a[r] - a[l - 1]); 
	}

	return 0; 
}