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
		string s;
		cin >> s;
		int l=0, r=0, u=0, d=0;
		for(char c:s) {
			if(c == 'L') l++;
			else if(c == 'R') r++;
			else if(c == 'U') u++;
			else d++;
		}	
		int lr = min(l, r);
		int ud = min(u, d);
		string ans;
		if(lr && ud) {
			for(int i=0;i<lr;i++)
				ans += 'L';
			for(int i=0;i<ud;i++)
				ans += 'U';
			for(int i=0;i<lr;i++)
				ans += 'R';
			for(int i=0;i<ud;i++)
				ans += 'D';
		} else {
			if(lr == 0 && ud == 0) {
				// empty
			} else if(lr) {
				ans = "LR";
			} else {
				ans = "UD";
			}
		}
		cout << ans.size() << '\n';
		cout << ans << '\n';
	}	
	
}