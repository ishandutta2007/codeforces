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

const int INF = 1e9 + 7;

ll n, k, ans = 0;


ll cnt1(ll x) { // x is even
	if(x > n) return 0;
	ll cnt = 0;
	for(ll i=0;;i++) {
		ll l = x << i, r = l + (1ll << (i+1)) - 1;
		if(l > n) break;
		cnt += min(r, n) - l + 1;
		if(n <= r) break;
	}
	return cnt;
}


ll cnt2(ll x) { // x is odd
	if(x > n) return 0;
	ll cnt = 0;
	for(ll i=0;;i++) {
		ll l = x << i, r = l + (1ll << i) - 1;
		if(l > n) break;
		cnt += min(r, n) - l + 1;
		if(n <= r) break;
	}
	return cnt;
}

signed main()
{
	IO_OP;
	
	cin >> n >> k;
	ll l = 0, r = n/2;
	while(l <= r) {
		ll m = (l + r) / 2;
		ll mm = m * 2;
		if(cnt1(mm) >= k) l = m + 1;
		else r = m - 1;
	}
	ans = max(ans, 2*r);
	l = 0, r = n / 2;
	while(l <= r) {
		ll m = (l + r) / 2;
		ll mm = m * 2 + 1;
		if(cnt2(mm) >= k) l = m + 1;
		else r = m - 1;
	}
	ans = max(ans, 2*r+1);
	cout << ans << endl;
}