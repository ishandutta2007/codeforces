#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

_ n, ff, c = 1;

_ ask(_ x);
int main() {

	scanf("%lld", &n);
	_ l = 1, r = n-1, md = 0, s = 0;
	for(; l <= r; ) {
		md = (l+r)>>1;
		_ sv = md;
		md += n-ff%n;
		if(md > n) md -= n;
//		printf("c = %lld, l = %lld, r = %lld, md = %lld\n", c, l, r, sv);
		_ ts = ask(md);
		if(ts >= c) {
			s = sv;
			r = sv-1;
			++c;
		} else l = sv+1;
	}
	printf("! %lld\n", n-s+ff);
	fflush(stdout);

	return 0;
}

_ ask(_ x) {
	ff += x;
	printf("+ %lld\n", x);
	fflush(stdout);
	_ rv;
	scanf("%lld", &rv);
	return rv;
}