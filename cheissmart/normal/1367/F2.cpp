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

const int INF = 1e9 + 7, N = 2e5 + 7;

void solve() {
	int n;
	cin >> n;
	vi a(n), v;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		v.PB(a[i]);
	}
	sort(ALL(v)); v.resize(unique(ALL(v))-v.begin());
	for(int i = 0; i < n; i++) a[i] = lower_bound(ALL(v), a[i]) - v.begin();
	vi vis(v.size()), last(n), first(n);
	for(int i = n-1; i >= 0; i--) {
		if(vis[a[i]] == 0) last[i] = 1;
		vis[a[i]] = 1;
	}
	vis = vi(v.size());
	for(int i = 0; i < n; i++) {
		if(vis[a[i]] == 0) first[i] = 1;
		vis[a[i]] = 1;
	}
	vi dp(v.size()), dp2(v.size()), cnt(v.size()), cnt2(v.size());
	for(int i = 0; i < n; i++) cnt2[a[i]]++;
	int mx = 0;
	for(int i = 0; i < n; i++) {
		cnt[a[i]]++;
		cnt2[a[i]]--;
		if(a[i] && first[i]) {
			dp[a[i]] = max(dp[a[i]], max(dp2[a[i]-1], cnt[a[i]-1]) + 1);
		}
		else dp[a[i]] = max(dp[a[i]], dp[a[i]] + 1);
		dp[a[i]] = max(dp[a[i]], 1);
		if(last[i]) dp2[a[i]] = max(dp2[a[i]], dp[a[i]]);
		mx = max(mx, dp[a[i]]);
		if(a[i] + 1 < v.size()) {
			mx = max(mx, dp2[a[i]] + cnt2[a[i] + 1]);
			mx = max(mx, cnt[a[i]] + cnt2[a[i] + 1]);
		}
		// cout << a[i] << " " << dp[a[i]] << endl; 
	}
	for(int i = 0; i < v.size(); i++) mx = max(mx, cnt[i]);
	cout << n - mx << '\n';
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) solve();
	
}