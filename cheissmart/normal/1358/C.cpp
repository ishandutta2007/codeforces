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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 == x2 || y1 == y2) {
			cout << 1 << endl;
			continue;
		}
		int dx = x2 - x1, dy = y2 - y1;
		int tt = min(dx, dy);
		int ans = 1;
		ans += tt * (tt + 1);
		ans += (max(dx, dy) - tt) * (tt);
		ans -= tt;
		cout << ans << endl;
	}

	
}