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
		set<int> r, c;
		for(int i = 0; i < n; i++) r.insert(i);
		for(int i = 0; i < m; i++) c.insert(i);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				int t;
				cin >> t;
				if(t) r.erase(i), c.erase(j);
			}
		}
		if(min(r.size(), c.size()) & 1) cout << "Ashish" << endl;
		else cout << "Vivek" << endl;
	}
	
}