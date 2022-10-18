#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 30;

_ tc, n, m, c[maxn];

int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		memset(c, 0, sizeof c);
		scanf("%lld%lld", &n, &m);
		for(; n--; ) {
			char ch;
			scanf(" %c", &ch);
			++c[ch-'a'+1];
		}
		_ pc = 0, sc = 0;
		for(_ i = 1; i <= 26; ++i) {
			pc += c[i]>>1;
			sc += c[i]&1;
		}
		_ s = (pc/m)<<1;
		sc += (pc-pc/m*m)<<1;
		if(sc >= m) ++s;
		printf("%lld\n", s);
	}

	return 0;
}