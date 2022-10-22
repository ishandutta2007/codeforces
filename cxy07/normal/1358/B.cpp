//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const int mod = 1e9 + 7;

int T,n;
int a[MAXN];

signed main () {
	cin >> T;
	while(T--) {
		cin >> n;
		for(register int i = 1;i <= n; ++i)
			cin >> a[i];
		sort(a + 1,a + n + 1);
		int ans = n;
		for(register int i = n;i >= 1; --i) {
			if(a[i] > ans) ans--;
			else break;
		}
		cout << ans + 1 << endl;
	}
	return 0;
}