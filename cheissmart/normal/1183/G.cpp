#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

pi a[N];
int b[N];

void solve() {
	int n;
	cin >> n;
	for(int i=0;i<n;i++) b[i] = a[i].F = a[i].S = 0;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		a[x].F++, a[x].S += y;
	}
	sort(a, a+n, greater<pi>());
	int ans1 = 0, pre = INF;
	for(int i = 0; i < n; i++) {
		b[i] = min(pre - 1, a[i].F);
		pre = b[i], ans1 += b[i];
		if(b[i] == 0) break;
	}
	multiset<int> s;
	int j = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(b[i] == 0) break;
		while(j < n && a[j].F >= b[i]) {
			s.insert(a[j].S);
			j++;
		}
		ans += min(*s.rbegin(), b[i]);
		s.erase(s.lower_bound(*s.rbegin()));
	}
	cout << ans1 << " " << ans << '\n';
}

signed main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) solve();
	
}