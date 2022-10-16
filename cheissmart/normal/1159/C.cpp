#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[100005], b[100005], deg[100005];

int32_t main()
{
	IO_OP;
	
	set<pi> s;
	int n, m, ans = 0, mx = -INF, mn = INF;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		ans += a[i] * m;
		s.insert({a[i], i});
		deg[i] = m;
		mx = max(mx, a[i]);
	}
	for(int i=0;i<m;i++) {
		cin >> b[i];
		if(b[i] == mx) continue;
		if(s.empty()) {
			cout << -1 << endl;
			return 0;
		}
		auto p = s.upper_bound({b[i], INF});
		if(p != s.begin()) {
			int x = (*prev(p)).F, y = (*prev(p)).S;
			ans += b[i] - x;
			if(b[i] != x)
				deg[y]--;
			if(deg[y] <= 1)
				s.erase(prev(p));
		} else {
			cout << -1 << endl;
			return 0;
		}
		mn = min(mn, b[i]);
	}
	if(mx > mn){
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;
}