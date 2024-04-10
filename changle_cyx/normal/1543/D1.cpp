#include <bits/stdc++.h>

using namespace std; 

typedef long long s64; 
typedef pair<int, int> pii; 

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

int n, K; 

int query(int x) {
	printf("%d\n", x); 
	fflush(stdout); 

	int opt; 
	scanf("%d", &opt); 
	return opt; 
}

inline int calcplus(int x, int y) {
	int res = 0, cur = 1; 
	while (x || y) {
		res += (x % K + y % K) % K * cur; 
		x /= K, y /= K, cur *= K; 
	}

	return res; 
}

inline int calcminus(int x, int y) {
	int res = 0, cur = 1; 
	while (x || y) {
		res += (x % K - y % K + K) % K * cur; 
		x /= K, y /= K, cur *= K; 
	}

	return res; 
}
//iamweak
void work() {
	read(n), read(K); 
	
	int cur = 0; 
	for (int i = 0, t, op = 0; i < n; ++i) {
		if (query(t = op ? calcminus(cur, i) : calcplus(i, cur))) break; 
		op ^= 1, cur = calcminus(t, cur); 
	}
}

int main() {
	int T; 
	read(T); 

	while (T--) work(); 

	return 0; 
}