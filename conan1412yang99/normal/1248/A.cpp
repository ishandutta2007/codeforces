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
#define endl '\n'

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
		int n, m, x=0, y=0, xx=0, yy=0;
		cin >> n ;
		for(int i=0;i<n;i++) {
			int tt;
			cin >> tt;
			if(tt&1) x++;
			else y++;
		}
		cin >> m;
		for(int i=0;i<m;i++) {
			int tt;
			cin >> tt;
			if(tt&1) xx++;
			else yy++;
		}
		cout << x*xx + y*yy << endl;
	}	
	
}