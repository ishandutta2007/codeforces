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
	int n;
	cin >> n;
	int a[n];
	int ans = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] == 1)
			ans ++;
	}
	int ansa = min(ans, n - ans);
	ans -= ansa;
	ansa += ans / 3;
	cout << ansa;
}