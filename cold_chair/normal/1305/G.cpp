#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 262144;

int n, x, c[N], f[N];
int F(int x) { return f[x] == x ? x : (f[x] = F(f[x]));}
ll ans;
void mer(int x, int y) {
	if(!c[x] || !c[y]) return;
	ll w = x + y;
	x = F(x), y = F(y);
	if(x != y) {
		f[x] = y;
		ans += (ll) w * (c[x] + c[y] - 1);
		c[y] = 1;
	}
}

int main() {
	scanf("%d", &n);
	fo(i, 1, n) scanf("%d", &x), c[x] ++, ans -= x;
	c[0] ++;
	fo(i, 0, 2e5) f[i] = i;
	fd(i, N - 1, 1) {
		for(int j = i; j; j = (j - 1) & i) {
			mer(j, i ^ j);
		}
	}
	pp("%lld\n", ans);
}