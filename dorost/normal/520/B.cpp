/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, m, ans = 0;
	cin >> n >> m;
	swap (n, m);
	while (n > m){
		if (n % 2)
			ans ++, n ++;
		n /= 2;
		ans ++;
	}
	cout << ans + m - n;
}