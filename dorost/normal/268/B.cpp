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
	for (int i = 1; i < n; i++)
		ans += (n - i) * i;
	cout << ans;
}