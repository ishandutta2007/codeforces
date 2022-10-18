#pragma G++ optimize("Ofast")

#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E7+8;

int n, p[maxn], pc, a[maxn], x, big, f[maxn];
bitset<maxn> inp;
_ dp[maxn];

inline int read();
int main() {
	
	n = read();
	for( int i = 1; i <= n; ++i) {
		x = read();
		big = max(big, x);
		for(_ j = 1; j*j <= x; ++j) if(!(x%j)) {
			++a[j];
			if(j*j != x) ++a[x/j];
		}
	}
	inp.set(0);
	inp.set(1);
	for( int i = 2; i <= big; ++i) {
		if(!inp[i]) p[++pc] = i;
		for( int j = 1; j <= pc; ++j) {
			if(p[j]*i > big) break;
			inp.set(p[j]*i);
			if(!(i % p[j])) break;
		}
	}
	for( _ i = big; i >= 1; --i) if(a[i]) {
		dp[i] = a[i]*(i-1);
		for( int j = 1; j <= pc; ++j) {
			if(i*p[j] > big) break;
			dp[i] = max(dp[i], (a[i]-a[i*p[j]])*(i-1)+dp[i*p[j]]);
		}
	}
	_ s = -1E11;
	for(_ i = 1; i <= big; ++i) s = max(s, dp[i]+n);
	printf("%lld\n", s);
	
	return 0;
}

inline int read() {
	int x = 0;
	char ch = getchar();
	for(; !(ch >= '0' && ch <= '9'); ) ch = getchar();
	for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
	return x;
}