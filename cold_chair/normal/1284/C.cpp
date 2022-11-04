#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 3e5 + 5;

int n, mo;

ll fac[N];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &mo);
	fac[0] = 1; fo(i, 1, n) fac[i] = fac[i - 1] * i % mo;
	ll ans = 0;
	fo(i, 1, n) {
		ans = (ans + fac[i] * (n - i + 1) % mo * fac[n - i] % mo * (n - i + 1)) % mo;
	}
	pp("%lld\n", ans);
}