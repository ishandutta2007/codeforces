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
		int a, b, c ,d;
		cin >> a >> b >> c >> d;
		int x, y, x1, x2, y1, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		int xx = x - a + b, yy = y - c + d;
		if(!(x1 <= xx && xx <= x2 && y1 <= yy && yy <= y2)) {
			cout << "NO" << endl;
			continue;
		}
		if((a || b) && x1 == x2) {
			cout << "NO" <<  endl;
			continue;
		}
		if((c || d) && y1 == y2) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
	}

}