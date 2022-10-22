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
		if (i == 0)
			ans += abs(a[i]);
		else
			ans += abs(a[i - 1] - a[i]);
	}
	cout << ans;
}