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
		int x = 0, y = 0;
		int ans = 0;
		set<pair<pi, pi>> st;
		for(char c:s) {
			int xx = x, yy = y;
			if(c == 'N') {
				yy++;
			} else if(c == 'S') {
				yy--;
			} else if(c == 'W') {
				xx--;
			} else {
				xx++;
			}
			if(st.count(MP(MP(xx, yy), MP(x, y))) || st.count(MP(MP(x, y), MP(xx, yy)))) ans++;
			else ans+=5;
			st.insert(MP(MP(xx, yy), MP(x, y)));
			x = xx, y = yy;
		}
		cout << ans << endl;
	}	
	
}