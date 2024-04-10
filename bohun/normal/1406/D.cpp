#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, l, r) for (int i = r; l <= i; --i)
 
using ll = long long;
using namespace std;

const int N = 1e5 + 5;

int n, q;
ll a[N], d[N], s;

void F(ll x) {
	if (x >= 0) printf ("%lld\n", (x + 1) / 2);
	else printf ("%lld\n", x / 2);
}

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%lld", a + i);
	rep(i, 1, n - 1) {
		d[i] = a[i] - a[i + 1]; 
		if (d[i] > 0) s += d[i];
	}
	F(s + a[n]);
	scanf ("%d", &q);
	while (q--) {
		int l, r, x;
		scanf ("%d%d%d", &l, &r, &x);
		if (l != 1) {
			if (d[l - 1] > 0) s -= d[l - 1];
			d[l - 1] -= x;
			if (d[l - 1] > 0) s += d[l - 1];
		}
		if (r != n) {
			if (d[r] > 0) s -= d[r];
			d[r] += x;
			if (d[r] > 0) s += d[r];
		}
		else a[n] += x;
		F(s + a[n]);
	}		
	return 0;
}