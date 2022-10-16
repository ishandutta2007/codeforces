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

const int INF = 1e9 + 7;

void solve() {
	int n, m;
	cin >> n >> m;
	vi a(n), b(n), c(m);
	V<vi> need(n);
	set<int> any;
	for(int i = 0; i < n; i++) cin >> a[i], a[i]--;
	for(int i = 0; i < n; i++) cin >> b[i], b[i]--;
	for(int i = 0; i < m; i++) cin >> c[i], c[i]--;
	int tot = 0;
	for(int i = 0; i < n; i++) {
		if(b[i] != a[i]) {
			need[b[i]].PB(i);
			any.insert(i);
			tot++;
		}
	}
	if(count(ALL(b), c.back()) == 0) {
		cout << "NO\n";
		return;
	}
	vi ans(m);
	int pos = find(ALL(b), c.back()) - b.begin();
	for(int i = 0; i < m; i++) {
		if(tot == 0) {
			ans[i] = pos;
			continue;
		}
		if(need[c[i]].size()) {
			ans[i] = need[c[i]].back();
			any.erase(ans[i]);
			need[c[i]].pop_back();
			tot--;
		} else {
			ans[i] = *any.begin();
		}
	}
	if(tot) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(int i = 0; i < m; i++)
		cout << ans[i] + 1 << " ";
	cout << '\n';
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