#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, x;
	cin >> n >> x;
	map<ll,int> m;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++m[a];
	}
	int ans = 0;
	while(m.size()) {
		auto[a, c] = *m.begin();
		m.erase(m.begin());
		while(c && m.count(a*x)) {
			if(--m[a*x] == 0)
				m.erase(a*x);
			--c;
		}
		ans += c;
	}
	cout << ans << '\n';
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}