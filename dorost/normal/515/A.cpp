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
	int a, b, s;
	cin >> a >> b >> s;
	a = abs(a);
	b = abs(b);
	if (a + b > s){
		return cout << "No", 0;
	}
	if ((s - (a + b)) % 2){
		return cout << "No", 0;
	}
	cout << "Yes";
}