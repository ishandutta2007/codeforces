#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;

int n, m;

void solve() {
	scanf("%d%d", &n, &m);
	multiset<int> s;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		s.insert(x);
	}
	ll ans = 0;
	for (int i = 1; i <= m; ++i) {
		int c;
		scanf("%d", &c);
		if (!s.empty()) {
			ans += c;
			s.erase(--s.end());
		}
		while (!s.empty() && *(s.begin()) == i) {
			s.erase(s.begin());
			ans += c;
		}
	}
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	
	return 0;
}