#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define P pair
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef P<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int l[200005], dp[200005];

int _dp(int i) {
	if(i >= 0) return dp[i];
	return 0;
}

int32_t main()
{
	IO_OP;
	
	memset(l, 0xff, sizeof l);

	int n, k;
	string s;
	cin >> n >> k >> s;
	deque<int> dk;
	s = ' ' + s;
	for(int i=1;i<=n;i++) {
		if(s[i] == '1')
			dk.push_back(i);
		while(dk.size() && i-dk.front()>k) dk.pop_front();
		if(dk.size()) l[i] = dk.front();
	}
	deque<pi> dc({MP(0, 0)});
	for(int i=1;i<=n;i++) {
		dp[i] = dp[i-1] + i;
		if(l[i] != -1) {
			int rr = max(0LL, l[i]-k-1);
			while(dc.size()&&dc.front().S < rr) dc.pop_front();
			dp[i] = min(dp[i], l[i]+dc.front().F);
		}
		while(dc.size() && dc.back().F >= dp[i]) dc.pop_back();
		dc.push_back(MP(dp[i],i));
	}
	cout << dp[n] << endl;
	
}