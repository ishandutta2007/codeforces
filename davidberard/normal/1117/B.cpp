#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

struct max2 {
	pii f, s;
	max2() : f(-1, -1), s(-1, -1) {}
	void insert(pii x) {
		if(x > f) {
			swap(f, s);
			f = x;
		} else if(x > s) {
			s = x;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	max2 mm;
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1;i<=n;++i) {
		int a;
		cin >> a;
		mm.insert(pii(a, i));
	}
	ll cc = m/(k+1);
	ll ans = cc*((ll) mm.f.first*k + mm.s.first) + (ll) (m-cc*(k+1))*mm.f.first;
	cout << ans << "\n";

	return 0;
}