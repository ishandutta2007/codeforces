#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;

const int nax = 3100;
const int mod = 998244353;

void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

char s[nax], t[nax];
int n, m;
int dp[nax][nax];

int main() {
	scanf ("%s", s);
	scanf ("%s", t);
	n = strlen(s);
	m = strlen(t);
	rep(i, 0, n - 1) {
		if (i >= m) {
			dp[0][i] = 1;
		}
		else if (t[i] == s[0])
			dp[0][i] = 1;
	}
	int ans = 0;
	rep(i, 0, n) {
		if (i + 1 >= m) add(ans, dp[i][0]);
		rep(l, 0, n - 1) {
			int r = l + i;
			if (r >= n) continue;
			if (l > 0 && (l - 1 >= m || t[l - 1] == s[i + 1]))
				add(dp[i + 1][l - 1], dp[i][l]);
			if (r + 1 < n && (r + 1 >= m || t[r + 1] == s[i + 1]))
				add(dp[i + 1][l], dp[i][l]);
		}
	}
	printf ("%d\n", 2 * ans % mod);
			
	
	return 0;
}