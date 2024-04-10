//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const int mod = 998244353;

int T, n, m, k, ans = 1;
int a[MAXN], b[MAXN];
int buk[MAXN];

signed main () {
	cin >> T;
	while(T--) {
		cin >> n >> k;
		for(int i = 1; i <= n; ++i) 
			cin >> a[i], buk[i] = 0;
		for(int i = 1; i <= k; ++i) {
			cin >> b[i];
			buk[b[i]] = i;
		}
		int cnt = 0;
		ans = 1;
		a[0] = a[n + 1] = n + 1;
		buk[n + 1] = INF;
		for(int i = 1; i <= n; ++i) {
			if(!buk[a[i]] || !buk[a[i - 1]] || !buk[a[i + 1]]) continue;
			if(buk[a[i - 1]] > buk[a[i]] && buk[a[i + 1]] > buk[a[i]]) {
				ans = 0;
				break;
			}
		}
		if(!ans) {
			cout << ans << endl;
			continue;
		}
		buk[a[0]] = 0;
		for(int i = 1;i <= n; ++i) {
			if(!buk[a[i - 1]] && buk[a[i]]) cnt++;
		}
		if(buk[a[1]]) cnt--;
		if(buk[a[n]]) cnt--;
		for(int i = 1; i <= cnt; ++i) {
			(ans *= 2) %= mod;
		}
		cout << ans << endl;
	}
	return 0;
}