#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int32_t main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int x, y, p, q;
		cin >> x >> y >> p >> q;
		if(p == 0) {
			if(x == 0)
				cout << 0 << endl;
			else
				cout << -1 << endl;
		}
		else if(q-p == 0) {
			if(y-x == 0)
				cout << 0 << endl;
			else
				cout << -1 << endl;
		} else {
			int n = (y - x + q - p - 1) / (q - p);
			n = max(n, (x + p - 1) / p);
			cout << n * q - y << endl;
		}
	}
	
}