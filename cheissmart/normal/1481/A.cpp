#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

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
		int x, y;
		string s;
		cin >> x >> y >> s;
		int xp = 0, yp = 0, xm = 0, ym = 0;
		for(char c:s) {
			if(c == 'R') xp++;
			else if(c == 'L') xm++;
			else if(c == 'U') yp++;
			else ym++;
		}
		if(x > 0 && x > xp) {
			cout << "NO" << '\n';
			continue;
		}
		if(y > 0 && y > yp) {
			cout << "NO" << '\n';
			continue;
		}
		if(x < 0 && -x > xm) {
			cout << "NO" << '\n';
			continue;
		}
		if(y < 0 && -y > ym) {
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES\n";
	}

}