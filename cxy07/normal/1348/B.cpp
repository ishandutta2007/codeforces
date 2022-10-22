//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int MAXN = 110;
const int INF = 2e9;
const int mod = 1e9 + 7;

int T,n,k,now;
int a[MAXN],b[MAXN],cnt[MAXN];

signed main () {
	cin >> T;
	while(T--) {
		cin >> n >> k;
		now = 0;
		for(register int i = 1;i <= n; ++i) {
			cin >> a[i];
			cnt[i] = 0;
		}
		for(register int i = 1;i <= n; ++i) {
			cnt[a[i]]++;
			if(cnt[a[i]] == 1) b[++now] = a[i];
		}
		if(now > k) {puts("-1"); continue;}
		for(register int i = 1;i <= n; ++i) {
			if(now < k && !cnt[i]) b[++now] = i;
			if(now >= k) break;
		}
		cout << now * n << endl;
		for(register int i = 1;i <= n; ++i)
			for(register int j = 1;j <= now; ++j)
				cout << b[j] << ' ';
		cout << endl;
	}
	return 0;
}