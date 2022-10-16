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

int32_t main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int a, b, c, ans = 0;
		cin >> a >> b >> c;
		for(int i=0;i<=a;i++) {
			if(i*2 <= b) {
				int r = i * 3;
				int bb = b - 2 * i;
				int tt = min(bb, c/2);
				r += tt * 3;
				ans = max(ans, r);
			}
		}
		cout << ans << endl;
	}	
	
}