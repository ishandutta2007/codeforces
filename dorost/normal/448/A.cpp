/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int a1, a2, a3, b1, b2, b3;
	cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
	int a = a1 + a2 + a3 + 4, b = b1 + b2 + b3 + 9;
	a /= 5;
	b /= 10;
	int n;
	cin >> n;
	if (a + b <= n){
		cout << "YES";
	}else{
		cout << "NO";
	}
}