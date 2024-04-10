/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int a, b;
	cin >> a >> b;
	int bag = 0;
	int ans = a;
	G:
	while (a){
		bag += a % b;
		a /= b;
		ans += a;
	}
	if (bag >= b){
		a = bag;
		bag = 0;
		goto G;
	}
	cout << ans << endl;
}