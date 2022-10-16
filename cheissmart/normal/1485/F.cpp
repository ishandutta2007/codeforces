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

const int INF = 1e9 + 7, M = 1e9 + 7;

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		map<ll, int> mp;
		int tot = 0;
		ll lz = 0;
		mp[0] = 1, tot++;
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			lz += x;
			int nw = (tot - mp[x - lz] + M) % M;
			(mp[x - lz] += nw) %= M;
			tot = (tot + nw) % M;
		}
		cout << tot << '\n';
	}

}