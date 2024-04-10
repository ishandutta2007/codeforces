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
	cin >> t;
	while(t--) {
		int a, b, c ,d;
		cin >> a >> b >> c >>d ;
		if(a == c) {
			if(b + d == a) {
				cout << "YES" << endl;
				continue;
			}
		}
		if(a == d) {
			if(b + c == a) {
				cout << "YES" << endl;
				continue;
			}
		}
		if(b == c) {
			if(a + d == c) {
				cout << "YES" << endl;
				continue;
			}
		}
		if(b == d) {
			if(a + c == b) {
				cout << "YES" << endl;
				continue;
			}
		}
		cout << "NO" << endl;
	}
	
}