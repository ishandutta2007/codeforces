
#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef long double _D;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef string str;
typedef const long long constant;

constant maxn = 2E5+8;

_ n, m, l[maxn], r[maxn], cnt, d[maxn];
char a[maxn], b[maxn], t;
bool c[maxn];

bool prt(_ x, _ ft, bool cn);
void dfs(_ x);
int main() {

	scanf("%lld%lld %s", &n, &m, a+1);
	for(_ i = 1; i <= n; ++i) scanf("%lld%lld", &l[i], &r[i]);
	dfs(1);
	for(_ i = n-1; i >= 1; --i) {
		if(b[i] != b[i+1]) t = b[i+1];
		c[d[i]] = b[i] < t;
	}
	prt(1, 1, true);
	putchar(10);

	return 0;
}

void dfs(_ x) {
	if(!x) return;
	dfs(l[x]);
	b[++cnt] = a[x];
	d[cnt] = x;
	dfs(r[x]);
	return;
}

bool prt(_ x, _ ft, bool cn) {
	if(!x) return false;
	bool t = prt(l[x], ft+1, cn);
	putchar(a[x]);
	if(cn && (t || (c[x] && ft <= m))) {
		putchar(a[x]);
		if(!t) m -= ft;
		ft = 1;
	} else ++ft;
	prt(r[x], ft, ft == 1);
	return ft == 1;
}