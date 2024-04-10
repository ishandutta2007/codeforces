#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int n;
pair<ll, ll> a[200005];
ll res;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		res += y;
		a[i] = {x, x + y};
	}

	sort(a, a + n);
	ll b = a[0].first;
	for (int i = 0; i < n; i++) {
		res += max(0ll, a[i].first - b);
		b = max(b, a[i].second);
	}
	cout << res << "\n";
	return 0;
}