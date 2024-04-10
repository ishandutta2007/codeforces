#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000009;
const int MOD = 1000000009;
int n, f[maxn], g[maxn];

int main(){
	scanf("%d", &n);
	f[0] = 0; f[1] = 4;
	for (int i=2; i<=n/2-2; i++)
		f[i] = (4 + 2 * f[i-1]) % MOD;
	g[n/2] = 1;
	for (int i=n/2-1; i>=1; i--)
		g[i] = (3LL * f[i-1] + 1LL * g[i+1] * (f[i-1] + 1) + 4) % MOD;
	printf("%I64d\n", 2LL * (1LL * g[1] * g[1] + 2 * g[1] + 2) % MOD);
	return 0;
}