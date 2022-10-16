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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vi t(n + 1), x(n);
	for(int i = 0; i < n; i++) cin >> t[i] >> x[i];
	t[n] = 1e18;
	int pos = 0, v = 0, tm = 0, endtime = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(t[i] >= endtime) {
			pos += v * (endtime - tm);
			v = 0, tm = t[i];
			if(pos == x[i]) {
				ans++;
				continue;
			}
			if(pos < x[i]) {
				v = 1;
				endtime = tm + x[i] - pos;
				if(endtime <= t[i + 1]) ans++;
			} else {
				v = -1;
				endtime = tm + pos - x[i];
				if(endtime <= t[i + 1]) ans++;
			}
		} else {
			int rt = min(endtime, t[i + 1]);
			int r = pos + v * (rt - tm);
			int l = pos + v * (t[i] - tm);
			if(l > r) swap(l, r);
			if(l <= x[i] && x[i] <= r) ans++;
		}
	}
	cout << ans << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) solve();
	
}