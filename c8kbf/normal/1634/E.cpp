

#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 4E5+8;

_ n, m, x, cnt, c[maxn], h[maxn];
vector<vector<_> > a;
vector<_> b;
map<_, _> mp;
struct ed {
	_ t, x, y;
};
vector<ed> g[maxn];
bitset<maxn> v;

void dfs(_ x);
int main() {

	scanf("%lld", &n);
	a.push_back(b);
	cnt = n;
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &m);
		b.clear();
		b.push_back(0);
		for(_ j = 1; j <= m; ++j) {
		 	b.push_back(0);
		 	scanf("%lld", &x);
		 	if(!mp.count(x)) mp[x] = ++cnt;
		 	x = mp[x];
		 	++c[x];
			g[i].push_back((ed){x, i, j});
			g[x].push_back((ed){i, i, j});
		}
		a.push_back(b);
	}
	for(_ i = n+1; i <= cnt; ++i) if(c[i] & 1) {
		puts("NO");
		exit(0);
	}
	puts("YES");
	for(_ i = 1; i <= cnt; ++i) if(!v[i]) dfs(i);
	for(_ i = 1; i <= n; ++i, putchar(10)) for(_ j = 1; j < (_)a[i].size(); ++j) putchar(~a[i][j] ? 'L' : 'R');

	return 0;
}

void dfs(_ x) {
	v.set(x);
	for(_ i = h[x]; i < (_)g[x].size(); i = h[x]) {
		++h[x];
		if(!a[g[x][i].x][g[x][i].y]) {
			a[g[x][i].x][g[x][i].y] = x < g[x][i].t ? 1 : -1;
			dfs(g[x][i].t);
		}
	}
	return;
}