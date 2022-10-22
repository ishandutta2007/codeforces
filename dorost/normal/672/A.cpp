/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	string ans;
	for (int i = 1; i < 500; i++){
		ans += to_string(i);
	}
	int k;
	cin >> k;
	cout << ans[k - 1];
}