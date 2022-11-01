#include <bits/stdc++.h>

using namespace std; 
// orzczk
const int mod = 1e9 + 7; 

inline void madd(int &x, const int &y) {
	x = x + y >= mod ? x + y - mod : x + y; 
}

const int MaxN = 750 + 5; 

int n; 
char s[MaxN]; 

int ans; 
int f[MaxN][2], g[MaxN][2]; 

int main() {
	scanf("%s", s + 1); 
	n = strlen(s + 1); 
	
	for (int d = 1; d <= 9; ++d) {
		memset(f, 0, sizeof(f)); 
		memset(g, 0, sizeof(g)); 
		
		f[0][0] = 1;  
		
		for (int i = 0; i < n; ++i)
			for (int opt = 0; opt <= 1; ++opt)
				if (f[i][opt]) {
					for (int j = 0, maxj = opt ? 9 : s[i + 1] - '0'; j <= maxj; ++j) {
						int nopt = opt || (j < maxj); 
						
						if (j <= d) madd(f[i + 1][nopt], f[i][opt]); 
						else madd(f[i + 1][nopt], 10LL * f[i][opt] % mod); 
						
						if (j < d) madd(g[i + 1][nopt], g[i][opt]); 	
						else if (j == d) madd(g[i + 1][nopt], (10LL * g[i][opt] + f[i][opt]) % mod); 
						else madd(g[i + 1][nopt], 10LL * g[i][opt] % mod); 
					}
				}
		
		ans = (ans + 1LL * d * (g[n][0] + g[n][1])) % mod; 
	}
	
	cout << ans << '\n'; 	
	return 0; 
}