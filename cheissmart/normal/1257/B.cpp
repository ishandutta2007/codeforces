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
	
	int t;
	cin >> t;
	while(t--) {
		int x, y;
		cin >> x >> y;
		 while(x < y) {
			if(x == 1) break;
			if(x == 2) {
				x = 3;
				break;
			}
			if(x % 2 == 0) x = x / 2 * 3;
			else x--;
		}
		if(x >= y) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
}