#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int n, m, x;
	cin >> n >> m;
	int a[n];
	if (n > m)
		return cout << 0, 0;
	int ans = 1;
	for (int i = 0; i < n; i++){
		cin >> x;
		a[i] = x;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans *= abs(a[i] - a[j]);
			ans %= m;
		}
	}
	cout << ans;
}