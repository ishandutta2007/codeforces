//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6 + 10;
const int add = 4e5 + 10;
const int INF = 2e9;
const int mod = 1e9 + 7;

int n,ans;
int a[MAXN],cnt[MAXN];

signed main () {
	cin >> n;
	for(register int i = 1;i <= n; ++i) {
		cin >> a[i];
		cnt[a[i] - i + add] += a[i];
	}
	for(register int i = 0;i < MAXN; ++i)
		ans = max(ans,cnt[i]);
	cout << ans << endl;
	return 0;
}