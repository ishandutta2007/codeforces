//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const int mod = 1e9 + 7;

int n,m,ans = 1;
int a[MAXN],b[MAXN];

signed main () {
	cin >> n >> m;
	for(register int i = 1;i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i] % m;
	}
	sort(b + 1,b + n + 1);
	for(register int i = 1;i < n; ++i)
		if(b[i] == b[i + 1]) return puts("0"),0;
	assert(n <= 1000);
	for(register int i = 1;i <= n; ++i) 
		for(register int j = 1;j < i; ++j)
			(ans *= abs(a[i] - a[j]) % m) %= m;
	cout << ans << endl;
	return 0;
}