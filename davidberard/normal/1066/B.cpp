#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 1100;
int dp[NMAX];
int have[NMAX];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, r;
	cin >> n >> r;
	memset(dp, 0x3f3f3f3f, sizeof dp);
	for(int i=1;i<=n;++i) cin >> have[i];
	ll ans = 0;
	int lst = 0;
	int cur = 0;
	while(cur < n) {
		int i;
		for(i=min(cur+r, n);i>lst;--i) {
			if(have[i]) break;
		}
		if(i == lst) {
			cout << -1 << endl;
			return 0;
		}
		++ans;
		lst = i;
		cur = i+r-1;
		//cerr << " cur " << cur << endl;
	}
	cout << ans << endl;
	
	return 0;
}