#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fst first
#define snd second
#define mp make_pair

#define rep(i, n) for(int i = 0; i < n; ++i)

#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d%d", &x, &y)
#define riii(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define ria(a, n) rep(_, n) scanf("%d", &a[_])

#define pi(x) printf("%d\n", x)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _==n-1?'\n': ' ')

#define Ttimes int T; scanf("%d", &T); while(T--)
typedef long long ll;

ll a[5010], b[5010], s[5010] = {};

ll d[5010][5010];
bool v[5010][5010] = {};
int n, m, k, sz = 1;
ll f(int x, int k) {
	if(k == 0) return 0;
	if(x >= sz) return -10000000000000LL;
	if(v[x][k]) return d[x][k];
	v[x][k] = true;
	return d[x][k] = max(b[x] + f(x + m, k - 1), f(x + 1, k));
}

int main() {
	riii(n, m, k);
	for(int i = 1; i <= n; ++i) { cin >> a[i]; s[i] = a[i] + s[i-1]; }

	for(int i = 1; i + m - 1 <= n; ++i) {
		b[sz++] = s[i + m - 1] - s[i-1];
	}

	// for(int i = 1; i < sz; ++i) cout << b[i] << ' '; cout << endl;

	cout << f(0, k) << endl;

	return 0;
}