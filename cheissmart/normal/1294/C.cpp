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

void solve() {
	int n;
	cin >> n;
	for(int i = 2; i <= 1000; i++) {
		if(n % i == 0) {
			int r = n / i;
			for(int j = 2; j * j <= r; j++) {
				if(r % j == 0) {
					int k = r / j;
					if(i != 1 && j != 1 && k != 1 && i != j && i != k && j != k) {
						cout << "YES" << endl;
						cout << i << " " << j << " " << k << endl;
						return;
					}
				}
			}
		}
	}
	cout << "NO" << endl;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		solve();
	}	
	
}