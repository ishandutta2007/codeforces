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
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n - (n + 3) / 4; i++)
			cout << '9';
		for (int i = 0; i < (n + 3) / 4; i++)
			cout << '8';
		cout << endl;
	}
}