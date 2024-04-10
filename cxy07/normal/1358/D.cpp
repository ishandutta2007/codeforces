//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5e5 + 10;
const int INF = 2e9;
const int mod = 1e9 + 7;

int n,x,L = 0,sum,now,ans;
int d[MAXN];

signed main () {
	cin >> n >> x;
	for(register int i = 1;i <= n; ++i) {
		cin >> d[i];
		d[i + n] = d[i];
	}
	for(register int i = 1;i <= (n << 1); ++i) {
		now += (d[i] + 1) * d[i] / 2;
		sum += d[i];
		if(sum <= x) {
			ans = max(ans,now);
			continue;
		}
		while(sum > x) {
			sum -= d[++L];
			now -= (d[L] + 1) * d[L] / 2;
		}
		int res = x - sum;
		ans = max(ans,now + (d[L] - res + 1 + d[L]) * res / 2);
	}
	cout << ans << endl;
}