/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	int a, b, c;
	cin >> a >> b >> c;
	int n, x, ans = 0;
	cin >> n;
	for (int i =0 ; i < n; i++){
		cin >> x;
		if (x > b && x < c)
			ans++;
	}
	cout << ans << endl;
}