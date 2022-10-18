#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef string str;
typedef const long long constant;

constant maxn = 2E3+8;

_ n, m, a[maxn][maxn], pa, pb, ca, cb;
char b[maxn][maxn];
vector<_p> g;

bool cmp(_p x, _p y);
int main() {

	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) {
		g.push_back(mp(i, j));
		scanf("%lld", &a[i][j]);
	}
	sort(g.begin(), g.end(), cmp);
	_p t = g[0];
	b[t.first][t.second] = 'M';
	pa = pb = t.first+t.second;
	ca = cb = t.first-t.second;
	for(_p i : g) if(i != t) {
		_ ds = max({abs(i.first+i.second-pa), abs(i.first+i.second-pb), abs(i.first-i.second-ca), abs(i.first-i.second-cb)});
		if(ds > m) b[i.first][i.second] = 'G';
		else {
			b[i.first][i.second] = 'M';
			pa = min(pa, i.first+i.second);
			pb = max(pb, i.first+i.second);
			ca = min(ca, i.first-i.second);
			cb = max(cb, i.first-i.second);
		}
	}
	for(_ i = 1; i <= n; ++i, putchar(10)) for(_ j = 1; j <= n; ++j) printf("%c", b[i][j]);

	return 0;
}

bool cmp(_p x, _p y) {
	return a[x.first][x.second] > a[y.first][y.second];
}