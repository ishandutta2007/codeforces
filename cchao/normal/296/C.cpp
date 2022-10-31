#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef complex<double> cd;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, a, b) for(int i = a; i <= b; ++i)
#define ri(a) scanf("%d", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define ria(a, n) rep(_, n) ri(a[_])
#define pia(a, n) rep(_, n) printf("%d ", a[_])
#define pi(x) printf("%d\n", x)
#define PB push_back
#define SZ size()
#define fst first
#define snd second
#define Ttimes int T; scanf("%d", &T); while(T--)
#define CASE  int T; scanf("%d", &T); for(int ks = 1; ks <= T; ++ks)

const int maxn = 100000 + 10;
int a[maxn], b[maxn], d[maxn], cnt[maxn] = {};
ll ans[maxn], ad[maxn] = {};
int main() {
	int n, m, k; riii(n, m, k);
	rep(i, n) {
		scanf("%I64d", &ans[i]);
	}
	rep(i, m) {
		riii(a[i], b[i], d[i]);
		a[i]--, b[i]--;
	}
	rep(i, k) {
		int aa, bb; rii(aa, bb);
		aa--, bb--;
		cnt[aa]++;
		cnt[bb + 1]--;
	}
	for(int i = 1; i < m; ++i) cnt[i] += cnt[i-1];

	// rep(i, m) printf("%d ", cnt[i]); puts("");

	rep(i, m) {
		// printf("%d - %d add %d\n", a[i], b[i], cnt[i] * d[i]);
		ad[a[i]] += 1LL * cnt[i] * d[i];
		ad[b[i]+1] -= 1LL * cnt[i] * d[i];
	}
	for(int i = 1; i < n; ++i) ad[i] += ad[i-1];
	// rep(i, n) printf("%I64d ", ad[i]); puts("");
	rep(i, n) printf("%I64d ", ans[i] + ad[i]); puts("");

	return 0;
}