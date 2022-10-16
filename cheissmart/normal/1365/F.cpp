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
		vi a(n), b(n);
		map<pi, int> cnt;
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) cin >> b[i];
		if((n & 1) && a[n/2] != b[n/2]) {
			cout << "No" << endl;
			continue;
		}
		for(int i = 0; i < n / 2; i++) {
			int x = a[i], y = a[n-i-1];
			if(x > y) swap(x, y);
			cnt[{x,y}]++;
		}
		bool no = false;
		for(int i = 0; i < n / 2; i++) {
			int x = b[i], y = b[n-i-1];
			if(x > y) swap(x, y);
			if(cnt[{x, y}] == 0) {
				cout << "No" << endl;
				no = true;
				break;
			}
			cnt[{x,y}]--;
		}
		if(!no) cout << "Yes" << endl;
	}
	
}