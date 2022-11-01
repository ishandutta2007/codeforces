#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
typedef long long ll;
typedef double ld;
typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1000 * 1000 * 1000, mod = inf + 7, ma = 1024 * 128;

int n, m, k, ans, u[4000][4000], c[4000][4000];

int fc(int i, int l, int r) {
	int ans = 0;
	if (l) ans += u[i - 1][l - 1];
	ans += c[l][r];
	re ans;
}

void div_con(int i, int L, int R, int ql, int qr) {
	if (L > R) re;
	int nu = ql, nu1 = ql;
	int pp, mid = (L + R) / 2, kk = fc(i, nu, mid); 
	for (int j = ql; j <= min(qr, mid); j++) {
		pp = fc(i, j, mid);
		if (pp < kk)
			nu = j, kk = pp; 
	}
	u[i][mid] = fc(i, nu, mid);
	div_con(i, L, mid - 1, ql, nu);
	div_con(i, mid + 1, R, nu, qr);
}

char cc;

int readint() {
	cc = getchar();
	while (cc < '0' || cc > '9') {
		cc = getchar();
	}
	int ans = 0;
	while (cc >= '0' && cc <= '9') {
		ans = ans * 10 + cc - '0';
		cc = getchar();
	}
	re ans;
}

int main() {
	//iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
	int nn, kk;
	n = readint();
	k = readint();
	forn (i, n)
		forn (j, n) {	
			u[i][j] = readint();
			if (j) u[i][j] += u[i][j - 1];
		}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			c[i][j] = c[i][j - 1] + u[j][j - 1];
			if (i) c[i][j] -= u[j][i - 1];
			//printf("%lld ", c[i][j]);
		}
		//Bprintf("\n");
	}
	forn (i, n)
		u[0][i] = c[0][i];
	for (int i = 1; i < k; i++) {
		div_con(i, 0, n - 1, 0, n - 1);
	}
	printf("%d", u[k - 1][n - 1]);
	re 0;
}