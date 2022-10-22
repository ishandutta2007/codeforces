#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;	

int n, d, m;
vector <int> x, y;
vector <ll> p;

int main() {
	scanf ("%d%d%d", &n, &d, &m);
	rep(i, 1, n) {
		int a;
		scanf ("%d", &a);
		if (a <= m) x.pb(a);
		else y.pb(a);
	}
	sort(all(x));
	x.pb(0);
	y.pb(0);
	sort(all(y));
	reverse(all(x));
	p.resize(ss(y));
	p[0] = 0;
	rep(i, 1, ss(y) - 1) p[i] = p[i - 1] + y[i];
	
	ll sum = 0, out = 0;
	rep(i, 0, ss(x) - 1) {
		sum += x[i];
		int r = min(ss(y) - 1, (n - i + d) / (d + 1));
		ll now = sum;
		if (r > 0) now += p.back() - p[ss(y) - r - 1];
		out = max(out, now);
	}
	printf ("%lld\n", out);
	return 0;
}