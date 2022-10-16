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
		if(n % 2 == 0) {
			k %= n;
			if(k == 0) k = n;
			cout << k << '\n';
		} else {
			k--;
			int x = (n + 1) / 2;
			int ans = (k % (x - 1) + (ll) k / (x - 1) * x) % n;
			cout << ans + 1 << '\n';
		}
	}

}