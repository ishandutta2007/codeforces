#include <bits/stdc++.h>

using namespace std; 

const int mod = 1000000000 + 7; 

inline void madd(int &x, const int &y) {
	x = x + y >= mod ? x + y - mod : x + y; 
}

inline void mdec(int &x, const int &y) {
	x = x - y < 0 ? x - y + mod : x - y; 
}

const int MaxN = 100 + 5; 
const int MaxA = 100 + 5; 

int n, c[MaxN], b[MaxN]; 
int sc[MaxN], sb[MaxN], s[MaxN]; 

int prod = 1; 
int ansmap[MaxN * MaxA]; 

int main() {
	scanf("%d", &n); 
	for (int i = 1; i <= n; ++i) {
		scanf("%d", c + i); 
		sc[i] = sc[i - 1] + c[i]; 
		prod = 1LL * prod * (c[i] + 1) % mod; 
	}
	for (int i = 1; i < n; ++i) {
		scanf("%d", b + i); 
		sb[i] = sb[i - 1] + b[i]; 
		s[i] = s[i - 1] + sb[i - 1]; 
	}
	s[n] = s[n - 1] + sb[n - 1]; 

	int lower = 10000, upper = 10000; 
	for (int i = 1; i <= n; ++i) {
		lower = min(lower, -(s[i] / i)); 
		upper = min(upper, (sc[i] - s[i]) / i); 
	}

	memset(ansmap, 255, sizeof(ansmap)); 

	int Q; 
	scanf("%d", &Q); 

	while (Q--) {
		int x; 
		scanf("%d", &x); 

		if (x < lower) printf("%d\n", prod); 
		else if (x > upper) puts("0"); 
		else if (~ansmap[x - lower]) printf("%d\n", ansmap[x - lower]); 
		else {
			static int f[MaxN * MaxA]; 
			int all = 0, ans = 0; 

			f[0] = 1; 
			for (int i = 1; i <= n; ++i) {
				all += c[i]; 

				int low = max(0, i * x + s[i]); 

				for (int j = all, cur = 0; j >= low; --j) {
					if (j >= c[i]) madd(cur, f[j - c[i]]); 
					mdec(cur, f[j]), madd(f[j], cur); 
				}
				for (int j = 0; j < min(low, all + 1); ++j) f[j] = 0; 
			}

			for (int i = 0; i <= all; ++i) madd(ans, f[i]), f[i] = 0; 

			printf("%d\n", ansmap[x - lower] = ans); 
		}
	}

	return 0; 
}