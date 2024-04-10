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
const int maxn = 200010;
const double eps = 1e-8;
int n, x, y, d[maxn] = {}, md = 0;
vector<int> g[maxn];

int l = 0;
int f(int x, int p) {
	int r = 0;
	for(int y : g[x]) if(y != p){
		r += f(y, x);
	}
	if(r >= 2) {
		l += r - 1;
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	riii(n, x, y);
	rep(i, n - 1) {
		int a, b;
		rii(a, b);
		a--, b--;
		g[a].PB(b);
		g[b].PB(a);
		d[a]++;
		d[b]++;
		md = max(md, max(d[a], d[b]));
	}
	if(n == 2) {
		cout << x << endl;
		return 0;
	}
	if(x >= y) {
		ll ans = 0;
		if(md == n - 1)
			ans = 1LL * (n - 2) * y + x;
		else
			ans = 1LL * (n - 1) * y;
		cout << ans << endl;
		return 0;
	}
	rep(i, n) if(d[i] > 1) {
		if(f(i, -1)) l++;
		break;
	}
	ll ans = 1LL * (l - 1) * y + 1LL * (n - l) * x;

	cout << ans << endl;

	return 0;
}