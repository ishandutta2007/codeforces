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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int N = 1e6 + 7;
const ll INF = 1e18 + 7;

bool no[N];

signed main()
{
	IO_OP;
	
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=0;i<m;i++) {
		int t;
		cin >> t;
		no[t] = 1;
	}
	vi v;
	for(int i=0;i<n;i++)
		if(!no[i]) v.PB(i);
	ll ans = INF;
	for(int cur=1;cur<=k;cur++) {
		int cost;
		cin >> cost;
		int r = 0, cnt = 0;
		while(r < n) {
			auto i = upper_bound(ALL(v), r) - v.begin();
			if(i == 0) break;
			int pos = v[i-1];
			if(pos + cur > r) {
				r = pos + cur;
			} else {
				break;
			}
			cnt++;
		}
		if(r >= n) {
			ans = min(ans, (ll)cnt * cost);
		}
	}
	if(ans == INF) ans = -1;
	cout << ans << endl;

}