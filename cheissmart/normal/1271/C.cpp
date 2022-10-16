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
	
	int n, x, y, a=0, b=0, c=0, d=0;
	cin >> n >> x >> y;
	for(int i=0;i<n;i++) {
		int xx, yy;
		cin >> xx >> yy;
		xx -= x, yy -= y;
		if(xx == 0) {
			if(yy > 0) a++;
			else c++;
		} else if(yy == 0) {
			if(xx > 0) d++;
			else b++;
		} else {
			if(xx > 0) d++;
			else b++;
			if(yy > 0) a++;
			else c++;
		}
	}
	int mx = max({a, b, c, d});
	cout << mx << endl;
	if(a == mx) {
		y++;
	} else if(b == mx) {
		x--;
	} else if(c == mx) {
		y--;
	} else {
		x++;
	}
	cout << x << " " << y << endl;
}