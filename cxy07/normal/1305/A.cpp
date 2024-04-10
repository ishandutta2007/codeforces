//Code By CXY
#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int MAXN = 110;
const int INF = 2e9;
const int mod = 1e9 + 7;

int T;
int n,a[MAXN],b[MAXN];

signed main () {
	cin >> T;
	while(T--) {
		cin >> n;
		for(register int i = 1;i <= n; ++i)
			cin >> a[i];
		for(register int i = 1;i <= n; ++i)
			cin >> b[i];
		sort(a + 1,a + n + 1);
		sort(b + 1,b + n + 1);
		for(register int i = 1;i <= n; ++i)
			cout << a[i] << ' ';
		cout << endl;
		for(register int i = 1;i <= n; ++i)
			cout << b[i] << ' ';
		cout << endl;
	}
	return 0;
}