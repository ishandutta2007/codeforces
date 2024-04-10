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
	int a[n], mn = 10000;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		for (int j = 0; j < i; j++){
			if (i == n - 1 && j == 0 || i - j == 1)
				mn = min(mn, abs(a[i] - a[j]));
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++){
			if (i == n - 1 && j == 0 || i - j == 1){
				if (mn == abs(a[i] - a[j])){
					return cout << i + 1 << ' ' << j + 1 << endl, 0;
				}
			}
		}
	}
}