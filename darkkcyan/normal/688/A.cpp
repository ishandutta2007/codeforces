#include <bits/stdc++.h>
using namespace std;

int main() {
	#define ll long long
	#define all(v) (v).begin(), (v).end()
	ll n, d; cin >> n >> d;
	ll ans = 0;
	ll c = 0;
	for (int i = 0; i < d; ++i) {
		string s; cin >> s;
		if (accumulate(all(s), 0) < 49 * n) ++c;
		else c = 0;
		ans = max(ans, c);
	}
	cout << ans;
	return 0;
}