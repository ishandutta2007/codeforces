/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	cin >> n;
	if (n == 2)
		return cout << -1, 0;
	cout << "385\n21\n165\n";
	for (int i = 0; i < n - 3; i++) {
		cout << 21 * (i + 100) << endl;
	}
}