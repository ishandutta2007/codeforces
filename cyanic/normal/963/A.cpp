#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
using namespace std;

const int maxn = 100005;
const int MOD = 1000000009;
int n, a, b, c, t, K, ans;
char s[maxn];

inline int power(int x, int p) {
	int res = 1;
	while (p) {
		if (p&1) res = 1LL * res * x % MOD;
		x = 1LL * x * x % MOD; p >>= 1;
	}
	return res;
}

inline int calc(int a, int b, int t) {
	int rev = power(b, MOD - 2), res = power(b, t);
	a = 1LL * a * rev % MOD;
	if (a == 1) return 1LL * res * (t + 1) % MOD;
	res = 1LL * res * (power(a, t+1)-1) % MOD
		* power(a-1+MOD, MOD-2) % MOD;
	return res;
}

int main() {
	scanf("%d%d%d%d", &n, &a, &b, &K); scanf("%s", s+1);
	t = n / K; c = calc(power(a, K), power(b, K), t);
	rep (i, 1, K)
		if (s[i] == '+') ans = (ans + 1LL * power(a, K-i) * power(b, i-1) % MOD * c) % MOD;
		else ans = (ans + MOD - 1LL * power(a, K-i) * power(b, i-1) % MOD * c % MOD) % MOD;
	printf("%d\n", ans);
	return 0;
}