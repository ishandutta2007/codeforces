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

vector<int> a[50010];
int mx = 0;
int pts[50010] = {};

int main() {
	int n, m;
	rii(n, m);
	rep(i, n) a[0].push_back(i + 1);
	int sz = 1;
	do {
		a[sz] = a[sz-1];
		if(next_permutation(a[sz].begin(), a[sz].end())) sz++;
		else break;
	} while(true);

	rep(t, sz) {
		rep(i, n) {
			int tmp = INT_MAX;
			repe(j, i, n - 1) {
				tmp = min(tmp, a[t][j]);
				pts[t] += tmp;
			}
		}
		mx = max(mx, pts[t]);
//		printf("%d: ", pts[t]);
//		pia(a[t], n);
	}

	rep(t, sz) {
		if(pts[t] != mx) continue;
		m--;
		if(m == 0) {
			pia(a[t], n);
			return 0;
		}
	}

	return 0;
}