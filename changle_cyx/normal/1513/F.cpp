#include <bits/stdc++.h>

typedef std::pair<int, int> pii; 

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

template <class T>
inline void relax(T &x, const T &y) {
	if (x < y) x = y; 
}

const int MaxN = 2e5 + 5; 

int n, a[MaxN], b[MaxN]; 
int ans; 

int main() {
	read(n); 
	
	long long sum = 0; 
	for (int i = 1; i <= n; ++i) {
		read(a[i]); 
	}
	for (int i = 1; i <= n; ++i) {
		read(b[i]); 
		sum += abs(a[i] - b[i]); 
	}

	int idx[MaxN]; 
	for (int i = 1; i <= n; ++i) idx[i] = i; 
	std::sort(idx + 1, idx + n + 1, [&] (const int &x, const int &y) {
		return std::min(a[x], b[x]) < std::min(a[y], b[y]); 
	}); 

	for (int j = 1, mx1 = 0, mx2 = 0; j <= n; ++j) {
		int i = idx[j]; 
		
		if (a[i] <= b[i]) {
			relax(ans, std::min(b[i], mx2) - a[i]); 
			relax(mx1, b[i]); 
		} else {
			relax(ans, std::min(a[i], mx1) - b[i]); 
			relax(mx2, a[i]); 
		}
	}
	
	std::cout << sum - ans * 2 << '\n'; 
	
	return 0; 
}