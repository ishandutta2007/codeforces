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

const int mod = 998244353;

int pt(int a, int b) {
	int c = 1;
	while(b) {
		if(b & 1)
			c = 1ll * c * a % mod;
		a = 1ll * a * a % mod;
		b /= 2;
	}
	return c;
}

int dp[2001][2001];

int n;
char s[2002];
int t[2001];
int pref[2001];
		
 
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; ++i) {
		if(s[i] == '(')
			t[i] = 0;
		if(s[i] == ')')
			t[i] = 1;
		if(s[i] == '?')
			t[i] = 2;
		pref[i] = pref[i - 1] + (t[i] == 2);
	}
	for(int l = 2; l <= n; ++l) {
		for(int p = 1; p + l - 1 <= n; ++p) {
			int k = p + l - 1;
			if(t[p] == 1) {
				dp[p][k] = dp[p + 1][k];
				continue;
			}
			if(t[k] == 0) {
				dp[p][k] = dp[p][k - 1];
				continue;
			}
			if(t[p] == 0 && t[k] == 1) {
				dp[p][k] = (dp[p + 1][k - 1] + pt(2, max(0, pref[k - 1] - pref[p]))) % mod;
				continue;
			}
			if(t[p] == 2 && t[k] == 1) {
				dp[p][k] = (dp[p + 1][k - 1] + dp[p + 1][k]) % mod;
				dp[p][k] = (dp[p][k] + pt(2, max(0, pref[k - 1] - pref[p]))) % mod;
				continue;
			}
			if(t[p] == 0 && t[k] == 2) {
				dp[p][k] = (dp[p][k - 1] + dp[p + 1][k - 1]) % mod;
				dp[p][k] = (dp[p][k] + pt(2, max(0, pref[k - 1] - pref[p]))) % mod;
				continue;
			}
			if(t[p] == 2 && t[k] == 2) {
				dp[p][k] = (dp[p + 1][k] + dp[p][k - 1]) % mod;
				dp[p][k] = (dp[p][k] + pt(2, pref[k - 1] - pref[p])) % mod;
			}
		}
	}
	printf("%d", dp[1][n]);
			
	
	
	return 0;
}