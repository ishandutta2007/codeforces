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

void solve() {
	int n, d;
	cin >> n >> d;
	for(int i=0;i<=n;i++) {
		int c = i + (d - 1) / (i + 1) + 1;
		if(i > (d - 1) / (i + 1) + 1 + 87)
			break;
		if(c <= n) {
			cout << "YES" << endl;
			return;
		}
	}	
	cout <<"NO" << endl;
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