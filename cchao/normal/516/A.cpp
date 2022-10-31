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

int n; string s;

int main() {
	cin >> n >> s;
	int cnt[10] = {};
	const int p[] = {2,3,5,7};
	rep(i, n) {
		int x = s[i] - '0';
		if(x <= 1) continue;
		repe(j, 2, x) {
			int t = j;
			rep(k, 4) while(t % p[k] == 0) {
				t /= p[k];
				cnt[p[k]]++;
			}
		}
	}
	for(int i = 3; i >= 0; --i) while(cnt[p[i]]) {
		putchar('0' + p[i]);
		repe(j, 2, p[i]) {
			int t = j;
			rep(k, 4) while(t % p[k] == 0) {
				t /= p[k];
				cnt[p[k]]--;
			}
		}
	}
	puts("");
	return 0;
}