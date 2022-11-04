#include<cstdio>
#define low(a) ((a) & -(a))
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
using namespace std;

const int N = 1005;

const int mo = 1000000007;

int n, m, k, S, a[N][N], ans, a2[N], b[N], s[1 << 12];
ll fac[11], nf[11];

ll ksm(ll x, ll y) {
	ll s = 1;
	for(; y; y /= 2, x = x * x % mo)
		if(y & 1) s = s * x % mo;
	return s;
}

ll C(ll x, ll y)  {
	return fac[x] * nf[x - y] % mo;
}

void dg(int x, int y, int p, int r) {
	if(y > m) {
		dg(x + 1, 1, 0, r);
		return;
	}
	if(x > n) {
//		printf("%d %d\n", b[1], b[2]);
//		printf("%d %d %d %d\n", p, r, s[r], s[S]);
		ans = ((ll) ans + C(k - s[S], s[r] - s[S])) % mo;
//		ans ++;
//		printf("%d\n", ans);
		return;
	}
	p |= b[y];
	if(k - s[p] - 1 < n + m - x - y - 1)
		return;
	if(a[x][y]) {
		if(p & a2[a[x][y] - 1]) return;
		b[y] |= a2[a[x][y] - 1];
		if((r & a2[a[x][y] - 1]) || (a2[a[x][y] - 1] == low(a2[k] - 1 - r)))
		dg(x, y + 1, p | b[y], r | a2[a[x][y] - 1]);
		b[y] -= a2[a[x][y] - 1];
	} else {
		int q = a2[k] - 1 - p;
		while(q) {
			b[y] |= low(q);
			if((low(q) & r) || (low(q) == low(a2[k] - 1 - r)))
			dg(x, y + 1, p | b[y], r | low(q));
			b[y] -= low(q);
			q -= low(q);
		}
	}
}

int main() {
	fac[0] = 1; fo(i, 1, 10) fac[i] = fac[i - 1] * i;
	nf[10] = ksm(fac[10], mo - 2);
	fd(i, 9, 0) nf[i] = nf[i + 1] * (i + 1) % mo;
	a2[0] = 1; fo(i, 1, 10) a2[i] = a2[i - 1] * 2;
	fo(i, 1, a2[10] - 1) s[i] = s[i - low(i)] + 1;
	scanf("%d %d %d", &n, &m, &k);
	if(n + m - 1 > k) {
		printf("0\n"); return 0;
	}
	fo(i, 1, n) fo(j, 1, m) {
		scanf("%d", &a[i][j]);
		if(a[i][j]) S |= a2[a[i][j] - 1];
	}
	dg(1, 1, 0, S);
	printf("%d", ans);
}