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

const int INF = 1e9 + 7, N = 2e7 + 7;

int lp[N], dp[N];

signed main()
{
	IO_OP;

	dp[1] = 0;
	for(ll i = 2; i < N; i++) {
		if(lp[i]) {
			dp[i] = dp[i / lp[i]] + (i / lp[i] % lp[i] ? 1 : 0);
			continue;
		}
		dp[i] = 1;
		for(ll j = i * i; j < N; j += i)
			lp[j] = i;
	}

	int t;
	cin >> t;
	while(t--) {
		int c, d, x;
		cin >> c >> d >> x;
		ll ans = 0;
		auto go = [&] (int g) {
			// c * A * B = x / g + d
			if((x / g + d) % c) return;
			int y = (x / g + d) / c;
			ans += 1LL << dp[y];
		};
		for(int g = 1; g * g <= x; g++) {
			if(x % g == 0) {
				go(g);
				if(x / g != g)
					go(x / g);
			}
		}
		cout << ans << '\n';
	} 

}