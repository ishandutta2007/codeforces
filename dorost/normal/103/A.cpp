/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	cin >> n;
	ll ans = n;
	ll a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
		ans += (a[i] - 1) * (i + 1);
	}
	cout << ans;
}