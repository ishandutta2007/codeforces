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

pi a[1005];

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i].F >> a[i].S;
		}
		sort(a, a+n);
		int x = 0, y = 0;
		bool ok = true;
		string s;
		for(int i = 0; i < n; i++) {
			if(a[i].S < y) {
				ok = false;
				break;
			}
			while(x < a[i].F) {
				x++;
				s += 'R';
			}
			while(y < a[i].S) {
				y++;
				s += 'U';
			}
		}
		if(ok){
			cout << "YES" << endl;
			cout << s << endl;
		} else cout << "NO" << endl;
	}	
	
}