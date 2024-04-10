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
		int n, g, b;
		cin >> n >> g >> b;
		int l = n, r = (ll)1e18 + 7;
		while(l <= r) {
			int m = (l + r) / 2;
			int good = m / (g + b) * g;
			good += min(g, m % (g + b));
			if(good >= (n+1)/2) r = m - 1;
			else l = m + 1;
		}
		cout << l << endl;
	}	
	
}