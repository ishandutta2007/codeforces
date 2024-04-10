/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, m;
	cin >> n >> m;
	int mn = 100000000;
	for (int i = 0; i <= n / 2; i++){
		int x = n - i * 2;
//		cout << x + i << endl;
		if ((x + i) % m == 0)
			mn = min(mn, (x + i));
	}
	if (mn == 100000000)
		cout << -1;
	else
		cout << mn;
}