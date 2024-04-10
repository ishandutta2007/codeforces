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

const int MaxN = 1e5 + 5; 

int n, a[MaxN]; 

void work() {
	read(n); 
	for (int i = 1; i <= n; ++i) read(a[i]); 

	static int p[MaxN]; 
	for (int i = 1; i <= n; ++i) p[i] = i; 

	sort(p + 1, p + n + 1, [=](int x, int y) {
		return a[x] < a[y] || (a[x] == a[y] && x < y); 
	}); 

	bool flg = true; 
	for (int l = 1, r; l <= n; l = r) {
		int suma = 0, sumb = 0; 
		for (r = l; r <= n && a[p[r]] == a[p[l]]; ++r) {
			suma += (r & 1) - (~r & 1); 
			sumb += (p[r] & 1) - (~p[r] & 1); 
		}

		if (suma != sumb) {
			flg = false; 
			break; 
		}
	}

	puts(flg ? "YES" : "NO"); 
}

int main() {
	int T; 
	read(T); 

	while (T--) work(); 

	return 0; 
}