/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int k;
	cin >> k;
	int a[12];
	for (int i = 0; i < 12; i++){
		cin >> a[i];
	}
	int mn = 13;
	int po = pow(2, 12);
	for (int i = 0; i < po; i++){
		int x = i;
		bool f[12] = {};
		for (int j = 0; j < 12; j++){
			f[j] = x % 2;
			x /= 2;
		}
		int sum = 0, num = 0;
		for (int j = 0; j < 12; j++){
			if (f[j]){
				num ++;
				sum += a[j];
			}
		}
		if (sum >= k)
			mn = min(mn, num);
	}
	if (mn == 13)
		cout << -1;
	else
		cout << mn;
}