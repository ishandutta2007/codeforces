#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#ifdef fread_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5+4, MOD = 1e9+7, BASE = 31;
char s[505];
int dp[505][505];
int solve (int l, int r) {
	if (l>r) return 0;
	if (dp[l][r]) return dp[l][r];
	dp[l][r] = solve(l+1,r) + 1;
	for (int i = l+1; i <= r; i++) {
		if (s[i] == s[l]) {
			dp[l][r] = min(dp[l][r],solve(l+1,i-1)+solve(i,r));
		}
	}
	return dp[l][r];
}
int main () { 
	int n;
	scanf ("%d",&n);
	scanf ("%s",s+1);
	printf ("%d\n",solve(1,n));
	return 0;
}