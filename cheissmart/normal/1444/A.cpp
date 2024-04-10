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

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		ll p, q;
		cin >> p >> q;
		ll ans = -1;
		auto go = [&] (ll x) {
			ll tmp = p;
			while(tmp % q == 0) {
				tmp /= x;
			}
			ans = max(ans, tmp);
		};
		for(int i = 2; i * i <= q; i++) {
			if(q % i == 0) {
				go(i);
				while(q % i == 0) q /= i;
			}
		}
		if(q != 1) go(q);
		cout << ans << endl;
	}
	
}