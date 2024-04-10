/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mn = *min_element(a, a + n), ans = 0;
	for (int i = 0; i < n; i++){
		int x = a[i] - mn;
		if (x % k)
			return cout << -1, 0;
		ans += (x / k);
	}
	cout << ans;
}