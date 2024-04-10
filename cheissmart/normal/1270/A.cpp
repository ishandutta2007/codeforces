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
	int t;
	cin >>t ;
	while(t--) {
		int n, x, y, mx1 = -INF, mx2 = -INF;
		cin >> n >> x >>y;
		for(int i=0;i<x;i++) {
			int t;
			cin >> t;
			mx1=max(mx1, t);
		}	
		for(int i=0;i<y;i++) {
			int t;
			cin >> t;
			mx2=max(mx2, t);
		}	
		if(mx1 > mx2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}