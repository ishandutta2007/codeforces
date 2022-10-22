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
	int a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = 1; i <= 2000000000000000000ll; i *= 2){
		for (int j = 1; j < i; j *= 2){
			if (((i - 1) - j) >= a && ((i - 1) - j) <= b && i != j * 2)
				ans ++;
		}
	}
	cout << ans;
}