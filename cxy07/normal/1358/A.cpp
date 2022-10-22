//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int MAXN = 1;
const int INF = 2e9;
const int mod = 1e9 + 7;

int T,n,m,ans;

signed main () {
	cin >> T;
	while(T--) {
		cin >> n >> m;
		ans = n * (m / 2);
		if(m & 1) ans += ceil(n / 2.0);
		cout << ans << endl;
	}
	return 0;
}