/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const ld P = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;

int32_t main(){
	cout << fixed << setprecision (120);
	int t;
	cin >> t;
	while (t--){
		ld n;
		cin >> n;
		n *= 2;
		ld sum = ((n - 2) * 180);
		ld each = sum / n;
		ld to = 90 - each / 2;
		ld x = 1.000 / (sin(to * P / 180));
		x *= x;
		x --;
		x = sqrt (x);
		cout << x << endl;
	}
}