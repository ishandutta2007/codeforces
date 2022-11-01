#include <bits/stdc++.h>

using namespace std; 

int mod; 

inline void madd(int &x, const int &y) {
	x = x + y >= mod ? x + y - mod : x + y; 
}

inline int mminus(int x, const int &y) {
	return x - y < 0 ? x - y + mod : x - y; 
}

const int MaxN = 500 + 5; 
const int MaxD = MaxN * MaxN; 

int n, M; 
int f[MaxN][MaxD], g[2][MaxD], h[2][MaxD]; 

int main() {
	cin >> n >> mod; 
	M = n * (n + 1) / 2 + 2; 

	f[0][M] = 1; 
	for (int j = M; j <= M * 2; ++j) g[0][j] = 1, h[0][j] = M; 

	for (int i = 1; i <= n; ++i) {
		int cur = i & 1, lst = cur ^ 1; 
		for (int j = 1; j <= M * 2; ++j) {
			if (i + j - 1 <= M * 2 && j - i >= 0) {
				f[i][j] = (1LL * mminus(g[lst][j + i - 1], g[lst][j - 1]) * (i + j)
				        +  1LL * (mod - 1) * mminus(h[lst][j + i - 1], h[lst][j - 1])
						+  1LL * mminus(g[lst][j - 1], g[lst][j - i]) * (i - j + mod)
						+  mminus(h[lst][j - 1], h[lst][j - i])) % mod; 
			}

			g[cur][j] = (g[cur][j - 1] + f[i][j]) % mod; 
			h[cur][j] = (h[cur][j - 1] + 1LL * f[i][j] * j) % mod; 
		}
	}
//orzzlt
	for (int i = 0; i <= n; ++i)
		for (int j = 2 * M; j >= 0; --j)
			madd(f[i][j], f[i][j + 1]); 

	int ans = 0; 
	for (int i = 1, pr = 1; i <= n; ++i) {
		for (int x = 1; x <= n - i + 1; ++x)
			for (int y = x + 1; y <= n - i + 1; ++y) {
				ans = (ans + 1LL * pr * f[n - i][y - x + M + 1]) % mod; 
			}	
		
		pr = 1LL * pr * (n - i + 1) % mod; 
	}
	
	cout << ans << '\n'; 
	return 0; 
}