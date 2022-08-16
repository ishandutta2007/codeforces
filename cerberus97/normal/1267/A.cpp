#include <bits/stdc++.h>

#define fast_cin() ios_base::sync_with_stdio(0); cin.tie(0)
#define pb push_back
 
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10;	
const ll inf = 2e18 + 42;

int main() {
	fast_cin();
	int n; cin >> n;
	vector<pll> events;
	for (int i = 1; i <= n; ++i) {
		ll a, b, t;
		cin >> a >> b >> t;
		events.pb({a, t});
		events.pb({b - t + 1, -t});
	}
	sort(events.begin(), events.end());
	multiset<ll> vals;
	ll ans = 0, ext = 0;
	int sz = events.size();
	events.pb({inf, 0});
	for (int i = 0; i < sz; ++i) {
		ll t = events[i].first, nt = events[i + 1].first;
		if (events[i].second > 0) {
			vals.insert(events[i].second);
		} else {
			vals.erase(vals.find(-events[i].second));
		}
		if (t == nt or vals.empty()) {
			ext = max(0ll, ext - (nt - t));
			continue;
		}
		ll c = *vals.begin();
		if (c < ext) {
			--ans;
			ext = 0;
		}
		ll k = (nt - ext - t + (c - 1)) / c;
		ans += k;
		ext = max(0ll, t + ext + k * c - nt);
	}
	cout << ans << '\n';
}