#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl
	
using namespace std;

const int nax = 1e6 + 11;
const int mod = 1e9 + 7;

int pt(int a, int b) {
	int c = 1;
	while(b) {
		if(b & 1) c = (ll) c * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return c;
}

int n, m;
int fac[nax];
int rev[nax];

int newton(int x, int y) {
	if(x < y)
		return 0;
	int z = fac[x];
	z = 1ll * z * rev[y] % mod;
	z = 1ll * z * rev[x - y] % mod;
	return z;
}

int main() {
	scanf("%d %d", &n, &m);
	fac[0] = rev[0] = 1;
	for(int i = 1; i < nax; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		rev[i] = pt(fac[i], mod - 2);
	}
	int ans = pt(m, n);
	for(int i = 1; i <= n; ++i)
		ans = (ans + 1ll * pt(m, i) * pt(m - 1, n - i) % mod * newton(n, i - 1) % mod) % mod;
	printf("%d", ans);
	
	
	
	return 0;
}