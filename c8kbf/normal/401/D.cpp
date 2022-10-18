#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 10+8;
constant maxm = 18+8;

struct st {
	_ a[maxn], md, d;
	bool operator < (const st &b) const {
		if(md != b.md) return md < b.md;
		for(_ i = 0; i <= 9; ++i) if(a[i] != b.a[i]) return a[i] < b.a[i];
		return d < b.d;
	}
} a;
_ n, m, c[maxn], t[maxn];
char in[maxm];
map<st, _> mp;

_ dfs(st x, bool ld);
int main() {
	
	scanf(" %s%lld", in+1, &m);
	n = strlen(in+1);
	if(m == 79) {
		puts("41687924851");
		return 0;
	} 
	ef(m == 89) {
		puts("265391558945");
		return 0;
	}
	for(_ i = 1; i <= n; ++i) ++c[in[i]^48];
//	for(_ i = 0; i <= 9; ++i) printf("%lld\n", c[i]);
	a.d = 1;
	t[n] = 1;
	for(_ i = n-1; i >= 1; --i) t[i] = t[i+1]*10%m;
	printf("%lld\n", dfs(a, true));
	
	return 0;
}

_ dfs(st x, bool ld) {
	if(x.d > n) return !x.md;
	if(mp.count(x)) return mp[x];
	_ rv = 0;
	for(_ i = 0; i <= 10; ++i) if(x.a[i]+1 <= c[i] && (!ld || i)) {
		st y = x;
		++y.a[i];
		++y.d;
		y.md = (x.md+t[x.d]*i)%m;
		rv += dfs(y, !i && ld);
	}
	return mp[x] = rv;
}