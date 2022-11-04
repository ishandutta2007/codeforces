#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2e5 + 5;

int n;
ll b[N], a[N];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n) scanf("%lld", &b[i]);
	ll mx = 0;
	fo(i, 1, n) {
		a[i] = b[i] + mx;
		mx = max(mx, a[i]);
		pp("%lld ", a[i]);
	}
}