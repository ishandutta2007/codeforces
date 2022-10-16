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

const int INF = 1e9 + 7, N = 3003;
const ll oo = 1e18;

vi G[N];
ll sum[N], dp[N], ans = 0;
int n, k;

V<pair<ll*, ll>> his;

void add(int i) {
	for(int j = k; j >= (int)G[i].size(); j--) {
		if(dp[j - G[i].size()] + sum[i] > dp[j]) {
			his.EB(&dp[j], dp[j]);
			dp[j] = dp[j - G[i].size()] + sum[i];
		}
	}
}

void backto(int tm) {
	while(his.size() > tm) {
		auto p = his.back();
		*p.F = p.S;
		his.pop_back();
	}
}

void DC(int l = 0, int r = n) {
	if(r - l == 1) { 
		ll sum = 0;
		for(int j = 0; j <= min(k, (int) G[l].size()); j++) {
			ans = max(ans, dp[k - j] + sum);
			if(j < G[l].size()) sum += G[l][j];
		}
		return;
	}
	int m = (l + r) / 2;
	{
		int tm = his.size();
		for(int i = m; i < r; i++)
			add(i);
		DC(l, m);
		backto(tm);
	}
	{
		int tm = his.size();
		for(int i = l; i < m; i++)
			add(i);
		DC(m, r);
		backto(tm);
	}
}

signed main()
{
	IO_OP;

	cin >> n >> k;
	for(int i = 1; i <= k; i++) dp[i] = -oo;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		G[i].resize(t);
		for(int &j:G[i]) cin >> j;
		sum[i] = accumulate(ALL(G[i]), 0LL);
	}
	DC();
	cout << ans << endl;
		
}