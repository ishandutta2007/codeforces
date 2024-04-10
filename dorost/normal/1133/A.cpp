#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int a, b, c, d;
	char ch;
	cin >> a >> ch >> b >> c >> ch >> d;
	int x = a * 60 + b, y = c * 60 + d;
	int ans = (x + y) / 2;
	int h = ans / 60, m = ans % 60;
	if (h < 10){
		cout << 0;
	}
	cout << h << ':';
	if (m < 10){
		cout << 0;
	}
	cout << m;
}