#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E7+8;
constant big = 5E6;

_ n, p[maxn], pc, dp[maxn], a[maxn], x;
bitset<maxn> inp;

int main() {
	
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &x);
		for(_ j = 1; j*j <= x; ++j) if(!(x%j)) {
			++a[j];
			if(j*j != x) ++a[x/j];
		}
	}
	inp.set(0);
	inp.set(1);
	for(_ i = 2; i <= big; ++i) {
		if(!inp[i]) p[++pc] = i;
		for(_ j = 1; j <= pc; ++j) {
			if(p[j]*i > big) break;
			inp.set(p[j]*i);
			if(!(i % p[j])) break;
		}
	}
	for(_ i = big; i >= 1; --i) {
		dp[i] = a[i]*(i-1);
		for(_ j = 1; j <= pc; ++j) {
			if(i*p[j] > big) break;
			dp[i] = max(dp[i], (a[i]-a[i*p[j]])*(i-1)+dp[i*p[j]]);
		}
	}
	_ s = -1E11;
	for(_ i = 1; i <= big; ++i) s = max(s, dp[i]+n);
	printf("%lld\n", s);
	
	return 0;
}