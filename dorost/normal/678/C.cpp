/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int lcm(int a, int b) {
	return ((a * b) / __gcd(a, b));
}

int32_t main(){
	int n, a, b, p, q;
	cin >> n >> a >> b >> p >> q;
	int x = n / a;
	int y = n / b;
	int z = n / (lcm(a, b));
	x -= z, y -= z;
	int ans = x * p + y * q + z * max(p, q);
	cout << ans;
}