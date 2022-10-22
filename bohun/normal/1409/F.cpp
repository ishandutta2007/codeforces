#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;

using namespace std;

const int N = 210;

int n, k;
char s[N], t[N];
int dp[N][N][N];

void umax(int &a, int b) {
	a = max(a, b);
}

int main() {
	scanf ("%d%d", &n, &k);
	scanf ("%s%s", s + 1, t + 1);
	
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			for (int g = 0; g <= n; ++g)
				dp[i][j][g] = -1e9;
	
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= i; ++j)
			for (int g = 0; g <= i; ++g) {
				
				// bez zmiany
				int st = t[1] == s[i];
				int nd = t[2] == s[i];
				
				umax(dp[i][j][g + st], dp[i - 1][j][g] + (nd ? g : 0));
				
				int same = t[1] == t[2];
				
				if (!j) continue;
				
				umax(dp[i][j][g + 1], dp[i - 1][j - 1][g] + (same ? g : 0));
				
				umax(dp[i][j][g + same], dp[i - 1][j - 1][g] + g);
			}
	int out = 0;
	for (int i = 0; i <= k; ++i)
		for (int j = 0; j <= n; ++j)
			umax(out, dp[n][i][j]);
	printf ("%d\n", out);		
	
	return 0;
}