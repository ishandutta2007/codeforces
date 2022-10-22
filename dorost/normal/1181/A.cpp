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
	int x, y, z;
	cin >> x >> y >> z;
	int x1 = x / z;
	int x2 = x % z;
	int y1 = y / z;
	int y2 = y % z;
	cout << (x1 + y1 + (x2 + y2 >= z)) << ' ';
	if (x2 + y2 >= z){
		cout << z - max(x2, y2);
	}else{
		cout << 0;
	}
}