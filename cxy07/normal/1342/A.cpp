//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1;
const int INF = 2e9;
const int mod = 1e9 + 7;

int T,x,y,a,b;

signed main () {
	cin >> T;
	while(T--) {
		cin >> x >> y >> a >> b;
		b = min(b,a * 2);
		cout << abs(x - y) * a + min(x,y) * b << endl;
	}
	return 0;
}