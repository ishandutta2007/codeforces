#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Line {
	mutable ll m, b, p;
	bool operator<(const Line& o) const { return m < o.m; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->m == y->m) x->p = x->b > y->b ? inf : -inf;
		else x->p = div(y->b - x->b, x->m - y->m);
		return x->p >= y->p;
	}
	void add(ll m, ll b) {
		auto z = insert({m, b, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.m * x + l.b;
	}
};

const int N = 200200;
int n;
ll a[N];
ll b[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
    b[i] = b[i-1]+a[i];
  }

  LineContainer container;
  container.add(0, -1e18);
  ll ans = 0;
  for (int i=1; i<=n; ++i) {
    container.add(a[i], b[i]-i*a[i]);
    ans = max(container.query(i)-b[i], ans);
  }

  container.clear();
  container.add(0, -1e18);
  for (int i=n; i>=1; --i) {
    container.add(a[i], b[i-1]-i*a[i]);
    ans = max(container.query(i)-b[i-1], ans);
  }
  ll extra = 0;
  for (int i=1; i<=n; ++i) {
    extra += a[i]*i;
  }
  cout << ans+extra<< "\n";

  return 0;
}