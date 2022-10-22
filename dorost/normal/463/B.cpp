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
	int a[n];
	int mn = 1000000000, ans = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (i == 0)
			continue;
		ans += (a[i - 1] - a[i]);
		mn = min(mn, ans);
	}
	cout << max(0, -mn) + a[0];
}