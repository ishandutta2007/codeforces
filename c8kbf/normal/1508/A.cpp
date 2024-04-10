#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef double _D;
typedef const long long constant;

_ tc, n;
str a, b, c;

str merge(str a, str b, char ch);
void read(str & a);
int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld", &n);
		read(a);
		read(b);
		read(c);
//		printf("merge = %s\n", merge(a, b).c_str());
		if(merge(a, b, '0').size() <= 3*n) printf("%s\n", merge(a, b, '0').c_str());
		ef(merge(a, c, '0').size() <= 3*n) printf("%s\n", merge(a, c, '0').c_str());
		ef(merge(b, c, '0').size() <= 3*n) printf("%s\n", merge(b, c, '0').c_str());
		ef(merge(a, b, '1').size() <= 3*n) printf("%s\n", merge(a, b, '1').c_str());
		ef(merge(a, c, '1').size() <= 3*n) printf("%s\n", merge(a, c, '1').c_str());
		ef(merge(b, c, '1').size() <= 3*n) printf("%s\n", merge(b, c, '1').c_str());
		else exit(1);
	}

	return 0;
}

void read(str & a) {
	a.clear();
	char ch;
	for(_ i = 1; i <= n<<1; ++i) {
		scanf(" %c", &ch);
		a += ch;
	}
	return;
}

str merge(str a, str b, char ch) {
	str rv;
	_ pa = 0, pb = 0;
	for(; pa < n<<1 || pb < n<<1; ) {
		if(pa >= n<<1) rv += b[pb++];
		ef(pb >= n<<1) rv += a[pa++];
		ef(a[pa] != ch) rv += a[pa++];
		ef(b[pb] != ch) rv += b[pb++];
		else {
			++pa;
			++pb;
			rv += ch;
		}
//		printf("pa = %lld, pb = %lld, rv = %s\n", pa, pb, rv.c_str());
	}
//	printf("rv = %s\n", rv.c_str());
	return rv;
}