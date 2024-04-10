//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define y1 ______y1

const int MAXN = 1;
const int INF = 2e9;
const int mod = 1e9 + 7;

int T,x1,y1,x2,y2;

signed main () {
	cin >> T;
	while(T--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << (x2 - x1) * (y2 - y1 ) + 1 << endl;
	}
	return 0;
}