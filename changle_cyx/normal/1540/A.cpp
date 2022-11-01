#include <bits/stdc++.h>
//orzczk
using namespace std; 

typedef long long s64; 

const int MaxN = 100000 + 5; 

int a[MaxN]; 

void work() {
	int n; 
	scanf("%d", &n); 
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i); 
	}

	sort(a + 1, a + n + 1); 

	s64 ans = a[n]; 
	for (int i = 2; i <= n; ++i)
		ans -= 1LL * a[i] * ((i - 1) - (n - i)); 
	
	printf("%lld\n", ans); 
}

int main() {
	int T; 
	scanf("%d", &T); 

	while (T--) work(); 

	return 0; 
}