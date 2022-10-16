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

	int n, m;
	cin >> n >> m;
	vi ans(m + 1, -1);
	ans[0] = 0;
	for(int i = 0; i < n; i++) {
		ll t, x, y;
		cin >> t >> x >> y;
		if(t == 1) {
			for(int j = m; j >= 0; j--) {
				if(ans[j] != -1) {
					ll ptr = j;
					for(int k = 0; k < y; k++) {
						ptr = ptr + (x + 99999) / 100000;
						if(ptr > m) break;
						if(ans[ptr] != -1) break;
						ans[ptr] = i + 1;
					}
				}
			}
		} else {
			for(int j = m; j >= 0; j--) {
				if(ans[j] != -1) {
					ll ptr = j;
					for(int k = 0; k < y; k++) {
						ptr = (ptr * x + 99999) / 100000;
						if(ptr > m) break;
						if(ans[ptr] != -1) break;
						ans[ptr] = i + 1;
					}
				}
			}
		}
	}
	for(int i = 1; i <= m; i++)
		cout << ans[i] << ' ';

}