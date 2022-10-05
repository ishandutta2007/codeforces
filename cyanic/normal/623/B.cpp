/*

a

1b
gcd1


a1ana1-1
a1 a1+1 an-1 an an+1
dp[i][j]i 
//

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1000009;
LL f[maxn], g[maxn], h[maxn], ans = 2e18;
int a[maxn], n, A, B;

LL calc(int x, int l, int r){
	memset(f, 0x3f, sizeof f);
	memset(g, 0x3f, sizeof g);
	memset(h, 0x3f, sizeof h);
	f[l-1] = 0; 
	for (int i=l; i<=r; i++){
		if ((a[i]-1) % x == 0 || (a[i]+1) % x == 0){
			f[i] = min(f[i], f[i-1]+B);
			h[i] = min(h[i], min(g[i-1], h[i-1])+B);
		}
		if (a[i] % x == 0){
			f[i] = min(f[i], f[i-1]);
			h[i] = min(h[i], min(g[i-1], h[i-1]));
		}
		g[i] = min(g[i], min(f[i-1], g[i-1])+A);
	}
	return min(f[r], min(g[r], h[r]));
}

LL solve(int x, int l, int r){
	LL best = 2e18;
	for (int i=2; i*i<=x; i++)
		if (x%i == 0){
			while (x%i == 0) x /= i;
			best = min(best, calc(i, l, r));
		}
	if (x >= 2) best = min(best, calc(x, l, r));
	return best;
}
/*
7 46 23
47 17 90 30 39 6 63
Answer:46
*/
int main(){
	scanf("%d%d%d", &n, &A, &B);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);
	ans = min(ans, solve(a[1]-1, 2, n) + B);
	ans = min(ans, solve(a[1], 2, n));
	ans = min(ans, solve(a[1]+1, 2, n) + B);
	ans = min(ans, solve(a[n]-1, 1, n-1) + B);
	ans = min(ans, solve(a[n], 1, n-1));
	ans = min(ans, solve(a[n]+1, 1, n-1) + B);
	printf("%I64d\n", ans);
	return 0;
}