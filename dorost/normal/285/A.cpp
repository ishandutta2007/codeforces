/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, k;
	cin >> n >> k;
	k++;
	for (int i = k; i > 0; i--){
		cout << i << ' ';
	}
	for (int i = k + 1; i <= n; i++){
		cout << i << ' ';
	}
}