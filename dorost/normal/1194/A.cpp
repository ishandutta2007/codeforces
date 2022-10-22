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
	vector <int> v;
	int x = 1;
	for (int i = 2; i < 100000; i++){
		v.push_back(x);
		x += 2;
	}
	int t;
	cin >> t;
	while (t--){
		int a, b;
		cin >> a >> b;
		int ans = b * 2;
		cout << ans << endl;
	}
}