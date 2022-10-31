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

int main() {
	int n, m; rii(n, m);
	int cc[110] = {};
	rep(i, m) {
		int c[110] = {};
		ria(c, n);
		int mx = *max_element(c, c + n);
		rep(j, n) if(c[j] == mx) {
			cc[j]++;
			break;
		}
	}
	int mx = *max_element(cc, cc + n);
	rep(i, n) if(cc[i] == mx) {
		pi(i + 1);
		break;
	}
	
	return 0;
}