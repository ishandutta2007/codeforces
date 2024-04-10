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
		int n;
		cin >> n;
		vi h(n), w(n);
		for(int i = 0; i < n; i++) cin >> h[i] >> w[i];
		vi hh(n), ww(n);
		iota(ALL(hh), 0), iota(ALL(ww), 0);
		sort(ALL(hh), [&](int i, int j){
			return h[i] < h[j];
		});
		sort(ALL(ww), [&](int i, int j){
			return w[i] < w[j];
		});
		vi ans(n, -1);
		set<pi> ws;
		for(int i = 0, j = 0; i < n; i++) {
			while(j < n && h[hh[j]] < h[hh[i]]) {
				ws.insert({w[hh[j]], hh[j]});
				j++;
			}
			auto it = ws.lower_bound({w[hh[i]], -INF});
			if(it != ws.begin()) {
				it--;
				ans[hh[i]] = it -> S + 1;
				assert(h[ans[hh[i]] - 1] < h[hh[i]] && w[ans[hh[i]] - 1] < w[hh[i]]);
			}
		}
		set<pi> hs;
		for(int i = 0, j = 0; i < n; i++) {
			while(j < n && w[ww[j]] < h[hh[i]]) {
				hs.insert({h[ww[j]], ww[j]});
				j++;
			}
			auto it = hs.lower_bound({w[hh[i]], -INF});
			if(it != hs.begin()) {
				it--;
				ans[hh[i]] = it -> S + 1;
			}
		}
		for(int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
	}
	
}