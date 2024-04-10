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
	int r, x, y, x1, y1;
	cin >> r >> x >> y >> x1 >> y1;
	int d1 = abs (x - x1);
	int d2 = abs (y - y1);
	r *= 2;
 	ld z = (d1 * d1) + (d2 * d2);
	z = sqrt (z);
	cout << ceil((z) / (ld)r);
}