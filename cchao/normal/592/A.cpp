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

char s[10][10];
int main() {
	rep(i, 8) rs(s[i]);
	int a = 22, b = 22;
	rep(i, 8) rep(j, 8) {
		if(s[i][j] == 'B') {
			bool fg = false;
			for(int k = i + 1; k < 8; ++k) if(s[k][j] != '.') fg = true;
			if(!fg) b = min(b, 7 - i);
		}
		if(s[i][j] == 'W') {
			bool fg = false;
			for(int k = i - 1; k >= 0; --k) if(s[k][j] != '.') fg = true;
			if(!fg) a = min(a, i);
		}
	}
	if(a <= b) puts("A");
	else puts("B");
	return 0;
}