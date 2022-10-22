/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, s;
	cin >> n >> s;
	int mx = -1;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (s * 100 >= x * 100 + y) {
 			mx = max(mx, (100 - y) % 100);
		}
	}
	cout << mx;
}