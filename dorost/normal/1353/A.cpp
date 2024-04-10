/*	* In the name of GOD
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		if (n == 1)
			cout << 0 << endl;
		else if (n == 2) 
			cout << m << endl;
		else
			cout << m * 2 << endl;
	}
}