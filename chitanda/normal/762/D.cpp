#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll inf = 1LL << 58;
const int maxn = 100100;
int n;
int a[maxn], b[maxn], c[maxn];
ll f[maxn], g[maxn], h[maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	for(int i = 1; i <= n; ++i) scanf("%d", b + i);
	for(int i = 1; i <= n; ++i) scanf("%d", c + i);
	f[1] = a[1];
	g[1] = h[1] = -inf;
	ll c2a = -inf, a2c = -inf;
	for(int i = 2; i <= n + 1; ++i){
		c2a = max(c2a + c[i - 1], h[i - 1]) + a[i - 1] + b[i - 1];
		a2c = max(a2c + a[i - 1], f[i - 1]) + b[i - 1] + c[i - 1];
		g[i] = max(g[i - 1], max(f[i - 1], h[i - 1]) + b[i - 1]) + b[i];
		f[i] = max(max(f[i - 1], g[i - 1] + a[i - 1]), c2a) + a[i];
		h[i] = max(max(h[i - 1], g[i - 1] + c[i - 1]), a2c) + c[i];
	}
	printf("%lld\n", h[n + 1]);
	return 0;
}