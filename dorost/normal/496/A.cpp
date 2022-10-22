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
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mn = 100000000;
	for (int i = 0; i < n - 2; i++){
		int mx = a[i + 2] - a[i];
		for (int j = 1; j <= i; j++){
			mx = max(mx, a[j] - a[j - 1]);
		}
		for (int j = i + 2; j < n - 1; j++){
			mx = max(mx, a[j + 1] - a[j]); 
		}
		mn = min(mn, mx);
	}
	cout << mn;
}