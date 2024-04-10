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
#define all(x) x.begin(), x.end()
#define pi(x) printf("%d\n", x)
#define PB push_back
#define SZ size()
#define fst first
#define snd second
#define Ttimes int T; scanf("%d", &T); while(T--)
#define CASE  int T; scanf("%d", &T); for(int ks = 1; ks <= T; ++ks)

int main() {
	int n, k; rii(n, k);
	vector<int> a(n);
	ria(a, n);
	int dif = *max_element(all(a)) - *min_element(all(a));
	if(dif > k) {
		puts("NO");
		return 0;
	}
	puts("YES");
	rep(i, n) {
		int v = a[i];
		rep(i, v) printf("%d ", i % k + 1);
		puts("");
	}
	return 0;
}