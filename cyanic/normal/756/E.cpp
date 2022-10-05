#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define pb push_back
using namespace std;
 
const int maxn = 300005, MOD = 1e9 + 7, T = 1e9;
int A[maxn], B[maxn], n, m, L, size, tmp, f;
vector<int> dp[maxn];
long long val[maxn];
char s[maxn];
 
int calc(int x) {
	if (L == 0) return 0;
	for (int i=L-1; i>=1; i--) {
		val[i-1] += val[i] % x * T;
		val[i] /= x;
	}
	int res = val[0] % x;
	val[0] /= x;
	while (L && !val[L-1]) L--;
	return res;
}
 
int main() {
	scanf("%d", &n);
	rep (i, 1, n-1) scanf("%d", &A[i]); A[n] = T;
	rep (i, 1, n) scanf("%d", &B[i]);
	scanf("%s", s + 1); m = strlen(s + 1);
	for (int i=m; i>=1; i-=9,L++) 
		for (int j=max(1, i-8); j<=i; j++)
			val[L] = val[L] * 10 + s[j] - '0';
	dp[1].pb(1);
	rep (i, 1, n) {
		size = dp[i].size(); f = 0;
		tmp = (A[i] == 1 ? 0 : calc(A[i]));
		rep (j, 0, size + B[i] - 1) {
			if (j <= size - 1) f = (f + dp[i][j]) % MOD;
			if (j >= B[i] + 1) f = (f - dp[i][j-B[i]-1] + MOD) % MOD;
			if (tmp == j % A[i]) dp[i+1].pb(f);
		}
	}
	printf("%d\n", L ? 0 : dp[n+1].empty() ? 0 : dp[n+1][0]);
	return 0;
}