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
		int n;
		cin >> n;
		vi a(n), b(n), c(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		
		b[0] = 0;
		c[0] = a[0];
		bool ok = 1;
		for(int i = 1; i < n; i++) {
			b[i] = b[i - 1];
			a[i] -= b[i];
			c[i] = a[i];
			if(c[i] > c[i - 1]) {
				b[i] += c[i] - c[i - 1];
				c[i] = c[i - 1];
			}
			if(c[i] < 0) ok = 0;
		}
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
}