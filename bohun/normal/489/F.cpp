#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl

using namespace std;

int n, m, mod;
char s[505];
int col[505];
int dp[505][505];
 
int main() {
	scanf("%d %d %d", &n, &m, &mod);
	for(int i = 1; i <= m; ++i) {
		scanf("%s", s + 1);
		int ile = 0;
		for(int j = 1; j <= n; ++j) {
			ile += s[j] == '1';
			col[j] += s[j] == '1';
		}
		if(ile != 2) {
			printf("0");
			return 0;
		}
	}
	int x = 0;
	int y = 0;
	
	for(int i = 1; i <= n; ++i) {
		if(col[i] == 0)
			x++;
		if(col[i] == 1)
			y++;
		if(col[i] > 2) 
			return printf("0");
	}
	dp[y][x] = 1;
	for(int i = y + x; 0 <= i; --i) {
		for(int a = 0; a <= i; ++a) {
			int b = i - a;
			if(a > 1) 
				dp[a - 2][b] = (dp[a - 2][b] + 1ll * a * (a - 1) / 2 % mod * dp[a][b] % mod) % mod;
			if(a > 0 && b > 0)
				dp[a][b - 1] = (dp[a][b - 1] + 1ll * a * b % mod * dp[a][b] % mod) % mod;
			if(b > 1)
				dp[a + 2][b - 2] = (dp[a + 2][b - 2] + 1ll * b * (b - 1) / 2 % mod * dp[a][b] % mod) % mod;
		}
	}
	
	printf("%d", dp[0][0]);
	
	
	return 0;
}