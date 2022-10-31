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

int main() {
	int n, cnt[1010] = {};
	ri(n);
	rep(i, n) {
		int t; ri(t);
		cnt[t]++;
	}
	int th = n - n / 2;
	rep(i, 1010) if(cnt[i] > th) {
		puts("NO");
		return 0;
	}

	puts("YES");
	return 0;
}