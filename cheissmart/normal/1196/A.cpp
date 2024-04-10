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

signed main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int ans = 0;
		int a[3];
		for(int i=0;i<3;i++) cin >> a[i];
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) for(int k=0;k<3;k++) {
			if(i != j && j != k && i != k) {
				int x = a[i], y = a[j], z = a[k];
				if(x > y) swap(x, y);
				if(x + z <= y) {
					ans = max(ans, x + z);
				} else {
					int t = (y + z - x) / 2;
					ans = max(ans, x + t);
				}
			}
		}
		cout << ans << endl;
	}	
	
}