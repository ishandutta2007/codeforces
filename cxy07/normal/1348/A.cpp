//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1;
const int INF = 2e9;
const int mod = 1e9 + 7;

int T,n,ans = 0;

signed main () {
	cin >> T;
	while(T--) {
		cin >> n;
		ans = 0;
		for(register int i = 1;i <= n / 2; ++i)
			ans += (1 << i);
		cout << ans << endl;
	}
	return 0;
}