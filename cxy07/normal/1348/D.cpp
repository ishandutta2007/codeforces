//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const int mod = 1e9 + 7;

int T,n,lim;
int now = 0,d,a[MAXN];

signed main () {
	cin >> T;
	while(T--) {
		cin >> n;
		now = 1;
		for(register int i = 1;; ++i) {
			d = i;
			now += (1ll << i);
			if(now >= n) break;
		}
		cout << d << endl;
		lim = d + 1;
		a[0] = 1;
		for(register int i = 1;i <= d; ++i) {
			a[i] = a[i - 1];
			a[i] += min((n - lim) / (d - i + 1),a[i - 1]);
			lim += min((n - lim) / (d - i + 1),a[i - 1]) * (d - i + 1);
		}
		//cout << d << endl;
		for(register int i = 1;i <= d; ++i)
			cout << a[i] - a[i - 1] << ' ';
		cout << endl;
	}
	return 0;
}