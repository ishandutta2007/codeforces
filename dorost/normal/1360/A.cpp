/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int a, b;
		cin >> a >> b;
		if (a < b)
			swap(a, b);
		cout << pow(max (a, b * 2), 2) << endl; 
	}
}