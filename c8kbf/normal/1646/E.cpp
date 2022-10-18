#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

constant maxn = 1E6+8;
constant lg = 30+8;

_ n, m, c[lg+8], s;
bitset<maxn*lg> a;
bitset<maxn> v;

int main() {

	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= 30; ++i) {
		c[i] += c[i-1];
		for(_ j = 1; j <= m; ++j) {
			if(!a.test(i*j)) ++c[i];
			a.set(i*j);
		}
//		c[i] = (_)st.size();
	}
//	printf("c = %lld\n", c[1]);
//	printf("c2 = %lld\n", c[2]);
	s = 1; 
	for(_ i = 2; i <= n; ++i) if(!v.test(i)) {
		_ t = 0;
		for(_ j = i; j <= n; j *= i) {
			++t;
			v.set(j);
		}
		s += c[t];
	}
	printf("%lld\n", s);

	return 0;
}