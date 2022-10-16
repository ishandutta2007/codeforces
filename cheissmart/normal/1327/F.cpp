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

const int INF = 1e9 + 7, N = 5e5 + 7, M = 998244353;

int a[N], l[N], r[N], x[N], dp[N], pre[N], psum[N];
int n, k, m;
vi ed[N];

int go(int bit) {
	for(int i=1;i<=n;i++) ed[i].clear();
	memset(a, 0, sizeof a);
	V<pi> v;
	for(int i=0;i<m;i++) {
		if(x[i] >> bit & 1) {
			a[l[i]]++;
			a[r[i]+1]--;
		} else {
			ed[r[i]].PB(l[i]);
		}
	}
	for(int i=1;i<=n;i++) a[i] += a[i-1];
	int mx = 0;
	for(int i=1;i<=n;i++) {
		pre[i] = mx;
		for(int j:ed[i]) mx = max(mx, j);
	}
	dp[0] = 1;
	if(a[1]) dp[1] = 0;
	else dp[1] = 1;
	psum[0] = dp[0], psum[1] = dp[1] + psum[0];
	for(int i=2;i<=n;i++) {
		if(a[i] == 0) dp[i] = (psum[i-1] - (pre[i] ? psum[pre[i] - 1] : 0) + M) % M;
		else dp[i] = 0;
		psum[i] = (psum[i-1] + dp[i]) % M;
	}
	int ans = (psum[n] - (mx ? psum[mx-1] : 0) + M) % M;
	return ans;
}


signed main()
{
	IO_OP;
	
	cin >> n >> k >> m;
	for(int i=0;i<m;i++) cin >> l[i] >> r[i] >> x[i];
	int ans = 1;
	for(int i=0;i<k;i++)
		ans = (ll) ans * go(i) % M;
	cout << ans << endl;
}