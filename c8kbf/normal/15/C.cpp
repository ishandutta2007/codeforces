#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

_ n, x, y, s;

_ preXor(_ x);
int main() {
	
	scanf("%lld", &n);
	for(; n--; ) {
		scanf("%lld%lld", &x, &y);
		s ^= preXor(x-1);
		s ^= preXor(x+y-1);
	}
	puts(s ? "tolik" : "bolik");

	return 0;
}

_ preXor(_ x) {
	if(!(x&1)) return x^preXor(x-1);
	_ rv = 1;
	if((x>>1)&1) rv ^= 1;
	return rv;
}