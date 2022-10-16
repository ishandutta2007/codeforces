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
	
	int n, cnt = 0;
	cin >> n;
	vi mxs, mns;
	int ans = 0;
	for(int i=0;i<n;i++) {
		int mx = -INF, mn = INF;
		int l;
		cin >> l;
		bool no = false;
		for(int j=0;j<l;j++) {
			int t;
			cin >> t;
			if(t > mn) no = true;
			mx = max(mx, t);
			mn = min(mn, t);
		}
		if(!no) {
			mxs.PB(mx);
			mns.PB(mn);
		}
		else ans += 2*n, cnt++;
	}
	ans -= cnt * cnt;
	sort(ALL(mns));
	for(int e:mxs)
		ans += lower_bound(ALL(mns), e) - mns.begin();
	cout << ans << endl;
}