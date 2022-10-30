#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

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

pair<int, int> a[100010];
ll s[100010] = {};

int main() {
	int n, d; rii(n, d);

	repe(i, 1, n) rii(a[i].F, a[i].S);
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i].S;

	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		int j = upper_bound(a + i, a + n + 1, pii(a[i].F + d, -1)) - a - 1;
		ans = max(ans, s[j] - s[i - 1]);
	}
	cout << ans << endl;

	return 0;
}