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
		int n, nn;
		cin >> n;
		nn = n;
		if(n == 3) {
			cout << "2\n3 2\n3 2" << endl;
			continue;
		}
		if(n == 4) {
			cout << "3\n3 4\n4 2\n4 2\n" << endl;
			continue;
		}
		int mx = n + 5;
		int k = min(64, n - 1);
		V<pi> ans;
		for(int i = 3; i <= n - 1; i++) {
			if(i != k) ans.EB(i, nn);
		}
		while(n != 1) {
			ans.EB(nn, k);
			n = (n + k - 1) / k;
		}
		int kk = k;
		while(k != 1) {
			ans.EB(kk, 2);
			k = (k + 1) / 2;
		}
		assert(ans.size() <= mx);
		cout << ans.size() << endl;
		for(pi p:ans)
			cout << p.F << " " << p.S << endl;
	}

}