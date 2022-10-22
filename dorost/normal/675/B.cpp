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
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	int ans = n;
	ans *= (n - (max({a + b, a + c, d + c, d + b}) - min({a + b, a + c, d + c, d + b})));
	cout << max(ans, 0ll);
}