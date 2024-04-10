

#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 3E5+8;

_ n, m, mod, a[maxn], b[maxn], f[maxn], x, y, c;

void upd(_ x, _ c);
int main() {

	scanf("%lld%lld%lld", &n, &m, &mod);
	f[1] = f[2] = 1;
	for(_ i = 3; i <= n+3; ++i) f[i] = (f[i-1]+f[i-2])%mod;
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &x);
		a[i] += x;
	}
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &x);
		a[i] -= x;
		a[i] %= mod;
	}
	b[1] = a[1];
	for(_ i = 2; i <= n; ++i) b[i] = (a[i]-a[i-1]-a[i-2])%mod;
	for(_ i = 1; i <= n; ++i) if(b[i]) ++c;
//	printf("c = %lld\n", c);
	for(; m--; ) {
		char ch;
		scanf(" %c%lld%lld", &ch, &x, &y);
		_ ts = ch == 'A' ? 1 : -1;
		upd(x, ts*1);
		upd(y+1, ts*-f[y-x+2]);
		upd(y+2, ts*-f[y-x+1]);
		puts(c ? "NO" : "YES");
	}

	return 0;
}

void upd(_ x, _ k) {
	if(x > n) return;
	if(!b[x]) ++c;
	b[x] += k;
	b[x] %= mod;
	if(!b[x]) --c;
	return;
}