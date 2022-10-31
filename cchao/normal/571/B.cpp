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
const int maxn = 300010;
const double eps = 1e-8;

int n, k;
int nn, kk;
int a[maxn], b[maxn];
long long d[5010][5010];
long long f(int aa, int bb) {
	long long &ret = d[aa][bb];
	if(ret >= 0) return ret;
	if(aa <= 1) {
		return 0;
	}
	int pos = (k - aa) * nn + (kk - bb);
	int *nb = b + pos;

	ret = 0;
	if(bb > 0 && aa >= bb)
		ret = max(ret, f(aa - 1, bb - 1) + nb[nn]);
	if(aa > bb)
		ret = max(ret, f(aa - 1, bb) + nb[nn - 1]);

	return ret;
}
int main() {
	memset(d, -1, sizeof d);
	rii(n, k);
	nn = n / k;
	kk = n % k;
	ria(a, n);
	sort(a, a + n);
	long long ans = 0;
	repe(i, 1, n - 1) {
		b[i - 1] = a[i] - a[i - 1];
		ans += b[i - 1];
	}
	ans -= f(k, kk);
	cout << ans << endl;
	return 0;
}