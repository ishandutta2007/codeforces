#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, a, b) for(int i = a; i <= b; ++i)
#define ri(a) scanf("%d", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define rs(s) scanf("%s", s)
#define pi(n) printf("%d\n", n)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _ == n - 1 ? '\n' : ' ')
#define ria(a, n) rep(_, n) scanf("%d", &a[_])
#define Ttimes int T; ri(T); for(int ks = 1; ks <= T; ++ks)
#define IO(name) freopen(name".in", "r", stdin);freopen(name".out", "w", stdout)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define F first
#define S second

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 100010;
const double eps = 1e-8;

char g[555][555] = {{}};
int s[555][555] = {};
int n, m, q;
int main() {
	rii(n, m);
	repe(i, 1, n) rs(g[i] + 1);
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1];
		if(g[i][j] == '.') {
			if(g[i][j-1] == '.') s[i][j]++;
			if(g[i-1][j] == '.') s[i][j]++;
		}
	}
	ri(q); while(q--) {
		int a, b, c, d;
		rii(a, b); rii(c, d);
		int ans = s[c][d] - s[a][d] - s[c][b] + s[a][b];
		repe(i, a + 1, c) if(g[i][b] == g[i-1][b] and g[i][b] == '.') ans++;
		repe(i, b + 1, d) if(g[a][i] == g[a][i-1] and g[a][i] == '.') ans++;
		printf("%d\n", ans);
	}
	return 0;
}