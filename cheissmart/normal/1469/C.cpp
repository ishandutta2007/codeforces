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

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vi h(n);
		for(int i = 0; i < n; i++) cin >> h[i];
		vi l(n, INF), r(n, -INF);
		l[0] = r[0] = h[0];
		for(int i = 1; i < n; i++) {
			int lb = l[i - 1], rb = r[i - 1] + k;
			int lbb = max(h[i], lb - k + 1), rbb = min(h[i] + k - 1, rb - 1);
			if(lbb <= rbb) l[i] = lbb, r[i] = rbb;
		}
		if(l[n - 1] <= h[n - 1] && h[n - 1] <= r[n - 1]) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}

}