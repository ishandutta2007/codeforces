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
#define int ll

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
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int r = a - b * c;
		if(r > 0) {
			cout << -1 << endl;
			continue;
		}
		auto go = [&] (int x) {
			int s = min(x - 1, c / d);
			return r * x + (c + (c - s * d)) * (s + 1) / 2 * b;
		};
		int lb = 0, rb = c / d + 1;
		while(lb < rb) {
			int mb = (lb + rb) / 2;
			if(go(mb) < go(mb + 1)) lb = mb + 1;
			else rb = mb;
		}
		cout << go(lb) << endl;
	}
	
}