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

int a[2020];

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int s = 0, c[2] = {};
		for(int i=0;i<n;i++) {
			int e;
			cin >> e;
			s += e & 1;
			c[e & 1]++;
		}
		if(s & 1) cout << "YES" << endl;
		else {
			if(c[0] && c[1]) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}	
	
}