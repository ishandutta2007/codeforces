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

pi a[200005];
int n, s;

bool ok(int m ){
	// can we have a median >= m ?
	int req = 0, at_most = n / 2, cnt = 0;
	for(int i=0;i<n;i++) {
		if(a[i].F >= m) req += a[i].F;
		else if(a[i].S < m) req += a[i].F, cnt++;
	}
	if(cnt > at_most) return false;
	for(int i=0;i<n;i++) {
		if(a[i].F < m && a[i].S >= m) {
			if(cnt < at_most) {
				req += a[i].F;
				cnt++;
			} else {
				req += m;
			}
		}
	}
	return req <= s;
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		cin >> n >> s;
		for(int i=0;i<n;i++) cin >> a[i].F >> a[i].S;
		sort(a, a+n);
		int l = 0, r = INF;
		while(l <= r) {
			int m = (l + r) / 2;
			if(ok(m)) l = m + 1;
			else r = m - 1;
		}
		cout << r << endl;
	}
	
}