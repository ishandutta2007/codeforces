#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;
constant srt = 317;

_ n, m, a[maxn], p[maxn], c[maxn], x, y;

_ blk(_ x);
int main() {
	
	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for(_ i = 1; i <= n; ++i) {
		_ p = i, t = 0;
		for(; blk(p) == blk(i); ++t) p += a[p];
		::p[i] = p;
		c[i] = t;
	}
	for(; m--; ) {
		scanf("%lld", &x);
		if(x) {
			scanf("%lld", &x);
			_ s = 1;
			for(; blk(p[x]) != blk(n+1); ) {
				s += c[x];
				x = p[x];
			}
			for(; blk(x+a[x]) != blk(n+1); ) {
				++s;
				x += a[x];
			}
			printf("%lld %lld\n", x, s);
		} else {
			scanf("%lld%lld", &x, &y);
			a[x] = y;
			for(_ i = x; blk(i) == blk(x); --i) if(blk(i+a[i]) > blk(x)) {
				c[i] = 1;
				p[i] = i+a[i];
			} else {
				c[i] = c[i+a[i]]+1;
				p[i] = p[i+a[i]];
			}
		}
	}
	
	return 0;
}

_ blk(_ x) {
	if(x <= 0) return -1;
	if(x > n) return blk(n)+1;
	return x/srt+1;
}