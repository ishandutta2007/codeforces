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
	int a, b, x , y, z;
	cin >> a >> b >> x >> y >> z;
	cout << max(0ll, x * 2 + y - a) + max(0ll, z * 3 + y - b);
}