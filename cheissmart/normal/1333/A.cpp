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
		int n, m;
		cin >> n >> m;
		if((n * m) & 1) {
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if((i+j)&1) cout << 'W';
					else cout << 'B';
				}
				cout << endl;
			}
		} else {
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(i == 0 && j == 0) cout << 'B';
					else{
						if((i+j)&1) cout << 'B';
						else cout << 'W';
					}
				}
				cout << endl;
			}
		}
	}	
	
}