#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int mo = 998244353;

const int N = 2e5 + 5;

int n, k;
int a[N], na[N];
int d[N], d0;

ll ans1, ans2;

int main() {
//	freopen("a.in", "r", stdin); 
	scanf("%d %d", &n, &k);
	fo(i, 1, n) scanf("%lld", &a[i]), na[a[i]] = i;
	fo(i, n - k + 1, n) {
		ans1 += i;
		d[++ d0] = na[i];
	}
	sort(d + 1, d + d0 + 1);
	ans2 = 1;
	fo(i, 2, d0) ans2 = ans2 * (d[i] - d[i - 1]) % mo;
	pp("%lld %lld\n", ans1, ans2);
}