#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
 
const int maxn = 300005;
const int mod = 1000000007;
int fac[maxn<<1], rev[maxn<<1], bin[maxn<<1], f[maxn];
int lena, lenb, n, equ, p, q, da, db, Da, Db, k, tmp, ans;
char a[maxn], b[maxn];
 
inline int power(int x, int p) {
	int res = 1;
	while (p) {
		if (p & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod; p >>= 1;
	}
	return res;
}
 
inline int C(int n, int m) {
	if (m < 0 || m > n) return 0;
	return 1ll * fac[n] * rev[n-m] % mod * rev[m] % mod;
}
 
inline int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}
 
void init() {
	scanf("%s%s%d", a + 1, b + 1, &n);
	lena = strlen(a + 1);
	lenb = strlen(b + 1);
 
	bin[0] = 1;
	rep (i, 1, 600000) {
		bin[i] = bin[i-1] + bin[i-1];
		if (bin[i] >= mod) bin[i] -= mod;
	}
	fac[0] = 1;
	rep (i, 1, 600000) 
		fac[i] = 1ll * i * fac[i-1] % mod;
	rev[600000] = power(fac[600000], mod - 2);
	per (i, 600000, 1)
		rev[i-1] = 1ll * i * rev[i] % mod;
		
	per (i, n, 1) {
		f[i] = 1ll * (n / i) * (n / i) % mod;
		for (int j = 2 * i; j <= n; j += i)
			f[i] = (f[i] + mod - f[j]) % mod;
		equ = (equ + 1ll * bin[i] * f[i]) % mod;
	}
}
 
int same() {
	if (lena != lenb) return 0;
	int cnt = 1;
	rep (i, 1, lena)
		if (a[i] != '?' && b[i] != '?' && a[i] != b[i])
			return 0;
		else if (a[i] == '?' && b[i] == '?')
			cnt = 2 * cnt % mod;
	return cnt;
}
 
int main() {
	init();
	rep (i, 1, lena) 
		if (a[i] == '?') p++;
		else if (a[i] == 'A') Da++;
		else if (a[i] == 'B') Db++;
	rep (i, 1, lenb)
		if (b[i] == '?') q++;
		else if (b[i] == 'A') Da--;
		else if (b[i] == 'B') Db--;
	rep (d, -q, p) {
		da = abs(Da + d);
		db = abs(Db + p - q - d);
		if (da == 0 && db == 0) {
			k = C(p + q, q + d);
			ans = (ans + 1ll * k * equ) % mod;
		}
		else if (1ll * (Da + d) * (Db + p - q - d) < 0) {
			k = C(p + q, q + d);
			tmp = max(da, db) / gcd(da, db);
			ans = (ans + 1ll * k * (bin[n/tmp+1] - 2)) % mod;
		}
	}
	if (k = same()) {
		ans = (ans + mod - 1ll * k * equ % mod) % mod;
		ans = (ans + 1ll * k * (bin[n+1] - 2) % mod * 
						   	   (bin[n+1] - 2)) % mod;
	}
	printf("%d\n", (ans + mod) % mod);
	return 0;
}