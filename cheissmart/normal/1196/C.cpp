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

signed main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int xmx = 1e5, xmn = -1e5, ymx = 1e5, ymn = -1e5;
		int n;
		cin >> n;
		for(int i=0;i<n;i++) {
			int x, y;
			cin >> x >> y;
			for(int j=0;j<4;j++) {
				int t;
				cin >> t;
				if(t == 0)  {
					if(j == 0) xmn = max(xmn, x);
					if(j == 1) ymx = min(ymx, y);
					if(j == 2) xmx = min(xmx, x);
					if(j == 3) ymn = max(ymn, y);
				}
			}
		}
		if(xmx >= xmn && ymx >= ymn) cout << 1 << " " << xmn << " "<< ymn << endl;
		else cout << 0 << endl;
	}	
	
}