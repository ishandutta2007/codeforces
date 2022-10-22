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
	int ans = 0;
	for (int i = 0; i < n; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		ans += (c - a + 1) * (d - b + 1);
	}
	cout << ans << endl;
}