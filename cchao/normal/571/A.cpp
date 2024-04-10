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

unsigned long long C[4][maxn] = {{}};
unsigned long long H(int a, int b) {
	return C[a - 1][b];
}
int a, b, c, l;
int main() {
	rep(i, 4) C[i][0] = 1;
	rep(i, maxn) C[0][i] = 1;
	repe(i, 1, 3) repe(j, 1, maxn - 1)
		C[i][j] = C[i-1][j] + C[i][j-1];
	riii(a, b, c); ri(l);
	unsigned long long ans = H(4, l);
	
	repe(i, 0, l) {
		if(b + c <= a + i) {
			ans -= H(3, min((a + i) - (b + c), l - i));
		}
		if(a + c <= b + i) {
			ans -= H(3, min((b + i) - (a + c), l - i));
		}
		if(a + b <= c + i) {
			ans -= H(3, min((c + i) - (a + b), l - i));
		}
	}
	
	cout << ans << endl;
	return 0;
}