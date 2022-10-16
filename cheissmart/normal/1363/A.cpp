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
		int n, x;
		cin >> n >> x;
		int a = 0, b = 0;
		for(int i = 0; i < n; i++) {
			int tt;
			cin >> tt;
			if(tt & 1) a++;
			else b++;
		}
		if(a == 0) cout << "No" << endl;
		else if(a >= x) {
			if(x & 1) cout << "Yes" << endl;
			else {
				if(b) cout << "Yes" << endl;
				else cout << "No" << endl;
			}
		}
		else {
			if(a % 2 == 0) a--;
			x -= a;
			if(x <= b) cout << "Yes" << endl;
			else cout << "No" << endl;
		}

	}	
	
}