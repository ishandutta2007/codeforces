//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1010;

int n;
int m[MAXN];
int ans[MAXN],out[MAXN],sum,tot;

signed main () {
	cin >> n;
	for(register int i = 1;i <= n; ++i)
		cin >> m[i];
	for(register int i = 1;i <= n; ++i) {
		sum = ans[i] = m[i];
		for(register int p = i - 1;p >= 1; --p) {
			ans[p] = min(ans[p + 1],m[p]);
			sum += ans[p];
		}
		for(register int p = i + 1;p <= n; ++p) {
			ans[p] = min(ans[p - 1],m[p]);
			sum += ans[p];
		}
		if(sum > tot) {
			tot = sum;
			for(register int p = 1;p <= n; ++p) out[p] = ans[p];
		}
	}
	for(register int i = 1;i <= n; ++i) cout << out[i] << ' ';
	cout << endl;
	return 0;
}