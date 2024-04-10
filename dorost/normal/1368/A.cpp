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
	int fib[100] = {1, 1};
	for (int i = 2; i < 100; i++){
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	int t = 1;
	cin >> t;
	while (t--){
		int a, b, n;
		cin >> a >> b >> n;
		if (a > b){
			swap(a, b);
		}
		for (int i = 1; i < 100; i++){
			if (fib[i] * b + fib[i - 1] * a > n){
				cout << i << endl;
				break;
			}
		}
	}
}