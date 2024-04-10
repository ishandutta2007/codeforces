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

int n, k, a[maxn];

int mex(int x) {
	if(x & 1) return x <= 3 ? 1 : 0;
	if(x <= 2) return 0;
	int aa = mex(x - 1);
	int bb = mex(x >> 1);
	if(aa > bb) swap(aa, bb);
	if(aa == 0) {
		if(bb == 0) return 1;
		if(bb == 1) return 2;
		return 1;
	}
	return 0;
}

int main() {
	rii(n, k);
	ria(a, n);

	int sum = 0;
	if(k % 2 == 0) {
		rep(i, n) sum ^= a[i] <= 2 ? a[i] : (a[i] % 2 == 0 ? 1 : 0);
	}
	else {
		rep(i, n) {
			sum ^= mex(a[i]);
		}
	}
	puts(sum == 0 ? "Nicky" : "Kevin");

	return 0;
}