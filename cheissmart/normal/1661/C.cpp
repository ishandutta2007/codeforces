#include <bits/stdc++.h>
#define IO_OP ios::sync_with_stdio(0), cin.tie(0)
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) (v).begin(), (v).end()
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;
const ll oo = 1e18;

signed main()
{
	IO_OP;
	int t;
	cin >> t;
	while(t--) [&] () {
		int n;
		cin >> n;
		vi h(n);
		for(int i = 0; i < n; i++)
			cin >> h[i];
		ll ans = oo;
		auto go = [&] (vi h) {
			ll res = 0;
			int mx = 0;
			for(int i = 0; i < n; i++) {
				if(h[i] & 1)
					h[i]++, res++;
				mx = max(mx, h[i]);
			}
			ll tot = 0;
			for(int i = 0; i < n; i++)
				tot += mx - h[i];
			ll ret = (tot + res) / 3 * 2;
			if((tot + res) % 3 == 1) ret++;
			else if((tot + res) % 3 == 2) ret += 2;
			res = max(res * 2 - 1, ret);
			ans = min(ans, res);
		};
		go(h);
		for(int i = 0; i < n; i++) h[i]++;
		go(h);
		cout << ans << '\n';
	} ();
	
}