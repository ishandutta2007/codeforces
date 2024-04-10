
#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef long double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef string str;
typedef const long long constant;

constant maxn = 2E5+8;

_ n, a[maxn], d[maxn], x, y, o[maxn], cx, cy, r;
v_ g[maxn];
_p dp[2][maxn];
bitset<maxn> v, lf;

void op(_ x, _ fa, _ d);
void dfs(_ x, _ fa);
int main() {

	scanf("%lld", &n);
	if(n == 2) {
		puts("2 2");
		puts("1 1");
		exit(0);
	}
	for(_ i = n; --i; ) {
		scanf("%lld%lld", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
		++d[x];
		++d[y];
		if(d[x] > 1) r = x;
		if(d[y] > 1) r = y;
	}
//	for(_ i = 1; i <= n; ++i) if(d[i] == 1) lf.set(i);
	dfs(r, -1);
	op(r, -1, 0);
	printf("%lld %lld\n", cx, cy);
	for(_ i = 1; i <= n; ++i) printf("%lld ", o[i]);
	putchar(10);

	return 0;
}

bool cmp(_p x, _p y) {
	if(x.first != y.first) return x.first > y.first;
	return x.second < y.second;
}

void dfs(_ x, _ fa) {
	for(_ i : g[x]) if(i != fa) dfs(i, x);
	dp[1][x].first = 1;
	dp[1][x].second = d[x];
	for(_ i : g[x]) if(i != fa) {
		dp[1][x].first += lf.test(i) ? 1 : dp[0][i].first;
		dp[1][x].second += lf.test(i) ? d[x] : dp[0][i].second;
		if(!lf.test(i) && cmp(dp[0][i], dp[1][i])) {
			dp[0][x].first += dp[0][i].first;
			dp[0][x].second += dp[0][i].second;
		} else {
			v.set(x);
			dp[0][x].first += lf.test(i) ? 1 : dp[1][i].first;
			dp[0][x].second += lf.test(i) ? 1 : dp[1][i].second;
		}
	}
//	printf("x = %lld, dp1 = %lld %lld, dp0 = %lld %lld\n", x, dp[1][x].first, dp[1][x].second, dp[0][x].first, dp[0][x].second);
	return;
}

void op(_ x, _ fa, _ d) {
	if(lf.test(x)) {
		o[x] = o[fa];
		cy += o[fa];
		++cx;
		return;
	}
	if(d) {
		o[x] = 1;
		++cy;
		for(_ i : g[x]) if(i != fa) op(i, x, 0);
	} else {
		if(cmp(dp[0][x], dp[1][x])) {
			o[x] = 1;
			++cy;
			for(_ i : g[x]) if(i != fa) op(i, x, 0);
		} else {
			o[x] = ::d[x];
			cy += ::d[x];
			++cx;
			for(_ i : g[x]) if(i != fa) op(i, x, 1);
		}
	}
	return;
}