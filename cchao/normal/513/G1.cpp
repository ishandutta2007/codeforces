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

int a[110];
int l[110], r[110], sz = 0;
int tot = 0, n, k;
double s = 0;

void dfs(int x) {
	if(x == k) {
		tot++;
		int cnt = 0;
		rep(i, n) rep(j, i) if(a[j] > a[i]) cnt++;
		s += cnt;
//		printf("%d: ", cnt);
//		pia(a, n);
		return ;
	}
	rep(i, sz) {
		reverse(a + l[i], a + r[i] + 1);
		dfs(x + 1);
		reverse(a + l[i], a + r[i] + 1);
	}
}

int main() {
	rii(n, k);
	ria(a, n);

	rep(i, n) rep(j, i + 1) {
		l[sz] = j;
		r[sz] = i;
		sz++;
	}

	dfs(0);

	printf("%.12f\n", s / tot);

	return 0;
}