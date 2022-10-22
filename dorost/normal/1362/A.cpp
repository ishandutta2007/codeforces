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
	int t = 1;
	cin >> t;
	while (t--){
		int a, b;
		cin >> a >> b;
		if (a > b){
			swap(a, b);
		}
		bool f = true;
		int ans = 0;
		while (b > a){
			if (b % 2)
				f = false;
			b /= 2;
			ans ++;
		}
		if (f && b == a){
			cout << (ans + 2) / 3;
		}else{
			cout << -1;
		}
		cout << endl;
	}
}