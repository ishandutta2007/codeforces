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
	int a[n];
	int mx = k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0)
			continue;
		mx = max(mx, a[i - 1] - a[i]);
	}
	cout << mx - k;
}