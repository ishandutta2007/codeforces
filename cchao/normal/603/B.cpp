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

bool v[1000000 + 10] = {};
int cnt[1000000 + 10] = {};
ll chz[1000000 + 10] = {};
int p, k;
const int mod = 1000000000 + 7;

int main() {
	rii(p, k);

	if(k == 0) {
		int ans = 1;
		for(int i = 1; i < p; ++i)
			ans = 1LL * ans * p % mod;
		pi(ans);
		return 0;
	}

	map<int, int> m;

	for(int i = 0; i < p; ++i) if(!v[i]) {
		int t = 0;
		for(int j = i; !v[j]; v[j] = true, j = 1LL * k * j % p, t++) ;
		cnt[t]++;
		chz[t]+=t;
	}

	int ans = 1;
	for(int i = 1; i <= p; ++i) if(cnt[i]) {
		rep(j, cnt[i])
			ans = ans * chz[i] % mod;
		for(int j = i + i; j <= p; j += i)
			chz[j] = (chz[j] + 1LL * cnt[i] * i) % mod;
	}

	pi(ans);

	return 0;
}