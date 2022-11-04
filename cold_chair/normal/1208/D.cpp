#include<bits/stdc++.h>
#define fo(i, x, y) for(ll i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(ll i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(ll i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const ll N = 2e5 + 5;

ll n;
ll s[N];
ll a[N];
ll t[N * 4];
ll v[N * 4], lz[N * 4];
ll pl, pr; ll px;
#define i0 i + i
#define i1 i + i + 1
void ad(ll i, ll y) {
	lz[i] += y;
	v[i] += y;
}
void down(ll i) {
	if(lz[i] != 0) {
		ad(i0, lz[i]);
		ad(i1, lz[i]);
		lz[i] = 0;
	}
}
void upd(ll i) {
	v[i] = min(v[i0], v[i1]);
	if(v[i1] <= v[i0]) t[i] = t[i1]; else t[i] = t[i0];
}
void add(ll i, ll x, ll y) {
	if(y < pl || x > pr) return;
	if(x >= pl && y <= pr) {
		if(x == y) t[i] = x;
		ad(i, px);
		return;
	}
	ll m = x+ y >> 1; down(i);
	add(i0, x, m); add(i1, m + 1, y);
	upd(i);
}

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%I64d", &n);
	fo(i, 1, n) {
		scanf("%I64d", &s[i]);
		pl = pr = i; px = s[i];
		add(1, 1, n);
	}
	fo(i, 1, n) {
		ll z = t[1]; a[z] = i;
		pl = pr = z; px = 1e18;
		add(1, 1, n);
		pl = z + 1, pr = n; px = -i;
		add(1, 1, n);
	}
	fo(i, 1, n) pp("%I64d ", a[i]);
}