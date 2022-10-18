#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

constant maxn = 2E5+8;

_ tc, n, x, y, o[maxn], c, d[maxn], e;
v_ g[maxn], a, b;
bitset<maxn> v;

void dfs(_ x, _ fa, _ d);
void ct(_ x, _ fa, _ d);
int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld", &n);
		for(_ i = 1; i <= n; ++i) {
			g[i].clear();
			d[i] = 0;
			v.reset(i);
		}
		c = 0;
		for(_ i = n; --i; ) {
			scanf("%lld%lld", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
			++d[x];
			++d[y];
		}
		ct(1, -1, 0);
		if(c > n>>1) {
			c = n-c;
			e = 1;
		} else e = 0;
		for(_ i = 1; i <= c; i <<= 1) if(c & i) {
			for(_ j = i; j < i<<1; ++j) {
				v.set(j);
				a.push_back(j);
			}
		}
//		printf("a: ");
//		for(_ i : a) printf("%lld ", i);
//		putchar(10);
		for(_ i = 1; i <= n; ++i) if(!v[i]) b.push_back(i);
		dfs(1, -1, 0);
		for(_ i = 1; i <= n; ++i) printf("%lld ", o[i]);
		putchar(10);
	}


	return 0;
}

void ct(_ x, _ fa, _ d) {
	if(!d) ++c;
	for(_ i : g[x]) if(i != fa) ct(i, x, d^1);
	return;
}

void dfs(_ x, _ fa, _ d) {
	if(d == e) {
		o[x] = a.back();
		a.pop_back();
	} else {
		o[x] = b.back();
		b.pop_back();
	}
	for(_ i : g[x]) if(i != fa) dfs(i, x, d^1);
	return;
}