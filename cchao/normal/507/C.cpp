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

ll f(int h, ll n, bool l = true) {
//	printf("%d %d %d\n", h, n, l);
	if(h == 0) return 0;
	bool fg = n <= (1LL << (h - 1));
	if(!fg) n -= (1LL << (h - 1));
	return 1LL + f(h - 1, n, l == fg ? !l : l) + (l != fg ? (1LL << h) - 1 : 0);
}

int main() {
	int h;
	ll n;
	cin >> h >> n;
	cout << f(h, n) << endl;
	return 0;
}