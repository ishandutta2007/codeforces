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

char s[maxn] = {};
int n;
int main() {

	ri(n);
	rs(s);

	int aa = 0, bb = 0;
	int ans = 1;
	for(int i = 1; i < n; ++i)
		ans += s[i] != s[i - 1];

	if(ans == 1) {
		if(n == 1) pi(1);
		else if(n == 2) pi(2);
		else pi(3);
		return 0;
	}

	for(int i = 1; i < n - 1; ++i) {
		if(s[i] == s[i-1] and s[i] != s[i+1]) aa = 1;
		if(s[i] == s[i+1] and s[i] != s[i-1]) {
			if(aa) {
				pi(ans + 2);
				return 0;
			}
			else bb = 1;
		}
		if(s[i] == s[i-1] and s[i] == s[i+1]) {
			pi(ans + 2);
			return 0;
		}
	}

	pi(ans + (aa or bb));

	return 0;
}