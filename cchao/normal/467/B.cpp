#include <bits/stdc++.h>
using namespace std;

int c[1<<20];
int main() {
	int n, m, k, a[1010]; cin >> n >> m >> k;
	for(int i = 0; i < m; ++i) cin >> a[i];
	for(int i = 0; i < (1<<n); ++i) c[i] = __builtin_popcount(i);
	int x, ans = 0; cin >> x;
	for(int i = 0; i < m; ++i) if(c[a[i]^x] <= k) ans++;
	cout << ans << endl;
	return 0;
}