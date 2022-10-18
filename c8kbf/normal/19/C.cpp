#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;
constant maxm = 1E7+8;
constant ts = 88888888;
constant mod = 1E9+7;
constant iv = 279411766;

_ n, a[maxn], b[maxn], cnt, p[maxn], r[maxn], s = 1;
map<_, _> mp;
struct pr {
	_ x, y;
	inline bool operator < (const pr &b) const {
		if(y-x != b.y-b.x) return y-x < b.y-b.x;
		return x < b.x;
	}
} c[maxm];
vector<_> g[maxn];

_ hsh(_ x, _ y);
int main() {
	
	scanf("%lld", &n);
	r[0] = 1;
	for(_ i = 1, j = ts; i <= n; ++i, j = j*ts%mod) {
		scanf("%lld", &a[i]);
		if(!mp.count(a[i])) mp[a[i]] = ++cnt;
		b[i] = mp[a[i]];
		g[b[i]].push_back(i);
		r[i] = r[i-1]*iv%mod;
		p[i] = (p[i-1]+b[i]*j)%mod;
	}
	_ sv = cnt;
	cnt = 0;
	for(_ k = 1; k <= sv; ++k) for(_ i = 0; i < g[k].size(); ++i) for(_ j = i+1; j < g[k].size(); ++j) {
		_ hl = g[k][j]-g[k][i];
		if(g[k][j]+hl-1 > n) continue;
		if(hsh(g[k][i], g[k][j]-1) == hsh(g[k][j], g[k][j]+hl-1)) c[++cnt] = (pr){g[k][i], g[k][j]+hl-1};
	}
	if(cnt) sort(c+1, c+1+cnt);
	for(_ i = 1; i <= cnt; ++i) if(c[i].x >= s) s = ((c[i].x+c[i].y)>>1)+1;
	printf("%lld\n", n-s+1);
	for(_ i = s; i <= n; ++i) printf("%lld ", a[i]);
	putchar(10);
	
	return 0;
}

_ hsh(_ x, _ y) {
	return (p[y]-p[x-1]+mod)*r[x]%mod;
}