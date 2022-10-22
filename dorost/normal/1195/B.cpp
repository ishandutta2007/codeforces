/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int n, k;
	cin >> n >> k;
	int x = sqrt (k * 2);
	for (int i = max(0ll, x - 100000); i <= x + 100000; i++){
		if ((i * (i + 1)) / 2 - (n - i) == k){
			return cout << n - i << endl, 0;
		}
	}
}