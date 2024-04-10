#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N], st[N][20];

void solve() {
	int n, p;
	cin >> n >> p;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		st[i][0] = a[i];
	}
	for(int j = 1; j < 20; j++)
		for(int i = 0; i + (1 << j) - 1 < n; i++)
			st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	set<int> s;
	for(int i = 0; i < n; i++) s.insert(i);
	ll ans = 0;
	vi order(n);
	iota(ALL(order), 0);
	sort(ALL(order), [&] (int i, int j) {
		return a[i] < a[j];
	});
	for(int i:order) {
		if(a[i] >= p) break;
		int l = i, r = i;
		for(int j = 19; j >= 0; j--)
			if(l - (1 << j) >= 0 && st[l - (1 << j)][j] % a[i] == 0)
				l -= 1 << j;
		for(int j = 19; j >= 0; j--)
			if(r + (1 << j) < n && st[r + 1][j] % a[i] == 0)
				r += 1 << j;
		auto it = s.lower_bound(l);
		if(it == s.end() || *it > r) continue;
		if(*it != l) {
			assert(it != s.begin());
			--it;
		}
		while(next(it) != s.end()) {
			auto itt = next(it);
			if(*itt <= r) {
				s.erase(itt);
				ans += a[i];
			} else {
				break;
			}
		}
	}
	ans += (ll(s.size()) - 1) * p;
	cout << ans << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	
}