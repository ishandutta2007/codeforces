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
		int n;
		cin >> n;
		if(n == 1) {
			cout << -1 << endl;
		} else {
			if((n-1)%3) {
				for(int i=0;i<n-1;i++) cout << 2;
				cout << 3 << endl;
			} else {
				cout << 2;
				for(int i=0;i<n-2;i++) cout << 4;
				cout << 3 << endl;
			}
		}
	}	
	
}