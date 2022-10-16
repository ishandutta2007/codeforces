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
		int h, w, n;
		cin >> w >> h >> n;
		ll ans = 1;
		while(w % 2 == 0 && ans < n) {
			w = w / 2;
			ans *= 2;
		}
		while(h % 2 == 0 && ans < n) {
			h = h / 2;
			ans *= 2;
		}
		if(ans >= n) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}