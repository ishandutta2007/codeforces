/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int x, y;
	cin >> x >> y;
	int a = abs(x) + abs(y);
	if (x < 0 && y < 0){
		cout << -a << ' ' << 0 << ' ' << 0 << ' ' << -a;
	}else if (x > 0 && y > 0){
		cout << 0 << ' ' << a << ' ' << a << ' ' << '0';
	}else if (x < 0 && y > 0){
		cout << -a << ' ' << 0 << ' ' << 0 << ' ' << a;
	}else{
		cout << 0 << ' ' << -a << ' ' << a << ' ' << 0;
	}
}