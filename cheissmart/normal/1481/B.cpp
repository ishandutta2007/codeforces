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
		auto go = [&] () {
			for(int i = 0; i < n; i++) {
				if(i == n - 1) return -1;
				if(h[i] >= h[i + 1]) continue;
				h[i]++;
				return i + 1;
			}
			throw;
		};
		int ans;
		for(int i = 0; i < k; i++) {
			ans = go();
			if(ans == -1) break;
		}
		cout << ans << endl;
	}

}