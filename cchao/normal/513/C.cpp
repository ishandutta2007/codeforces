#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef complex<double> cd;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, a, b) for(int i = a; i <= b; ++i)
#define ri(a) scanf("%d", &a)
#define rd(a) scanf("%lf", &a)
#define rs(a) scanf("%s", s)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define ria(a, n) rep(_, n) ri(a[_])
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _ == n - 1 ? '\n' : ' ')
#define pi(x) printf("%d\n", x)
#define PB push_back
#define SZ(X) ((int)X.size())
#define ALL(X) X.begin(), X.end()
#define fst first
#define snd second
#define Ttimes int T; scanf("%d", &T); while(T--)
#define CASE  int T; scanf("%d", &T); for(int ks = 1; ks <= T; ++ks)

int n, l[5], r[5];
int a[5][3];

long double ww = 0;
long double mm = 0;
long double tmp;
int chz[5];
void dfs(int x) {
	if(x == n) {
		int cnt[3] = {};
		rep(i, n) cnt[chz[i]]++;
		if(cnt[2] > 1 || cnt[1] == 0 || cnt[1] + cnt[2] == 1) return ;
		long double t = 1.0;
		rep(i, n) t *= a[i][chz[i]];
		tmp += t;
		return ;
	}
	rep(i, 3) if(a[x][i]) {
		chz[x] = i;
		dfs(x + 1);
	}
}

int main() {
	ri(n);
	rep(i, n) rii(l[i], r[i]);		

	repe(t, 1, 10000) {
		rep(i, n) {
			a[i][1] = l[i] <= t && t <= r[i] ? 1 : 0;
			a[i][0] = max(0, min(t, r[i]) - l[i] + 1) - a[i][1];
			a[i][2] = max(0, r[i] - max(t, l[i]) + 1) - a[i][1];
		}
		tmp = 0;
		dfs(0);
		ww += tmp * t;
		mm += tmp;
	}
	printf("%.12f\n", (double)(ww / mm));

	return 0;
}