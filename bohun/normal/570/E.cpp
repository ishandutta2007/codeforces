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

const int mod = 1e9 + 7;

int n, m;
int dp[2][501][501];
int ans = 0;
char s[501][501];

void add(int &a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
}

inline bool in(int row, int col) {
	return 1 <= row && row <= n && 1 <= col && col <= m;
}
 
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	if(s[1][1] != s[n][m]) 
		return printf("0"), 0;
	dp[1][1][n] = 1;
	for(int row = 1; row <= n; ++row) {
		int ja = row & 1;
		int on = !ja;
		
		for(int col = 1; col <= m; ++col)
			for(int rr = 1; rr <= n; ++rr)
				dp[on][col][rr] = 0;
		
		for(int col = 1; col <= m; ++col) 
			for(int rr = 1; rr <= n; ++rr) {
				int cc = n + m + 2 - row - col - rr;
				if(row + col - 2 + m + n - rr - cc > n + m - 2)
					continue;
				if(!dp[ja][col][rr])
					continue;
				if(abs(rr - row) + abs(col - cc) <= 1) {
					ans = (ans + dp[ja][col][rr]) % mod;
					continue;
				}
				if(in(row + 1, col) && in(rr - 1, cc) && s[row + 1][col] == s[rr - 1][cc])
					add(dp[on][col][rr - 1], dp[ja][col][rr]);
				if(in(row + 1, col) && in(rr, cc - 1) && s[row + 1][col] == s[rr][cc - 1])
					add(dp[on][col][rr], dp[ja][col][rr]);
				if(in(row, col + 1) && in(rr - 1, cc) && s[row][col + 1] == s[rr - 1][cc])
					add(dp[ja][col + 1][rr - 1], dp[ja][col][rr]);
				if(in(row, col + 1) && in(rr, cc - 1) && s[row][col + 1] == s[rr][cc - 1])
					add(dp[ja][col + 1][rr], dp[ja][col][rr]);
			}
	}
	printf("%d", ans);
				
				
	
	
	
	return 0;
}