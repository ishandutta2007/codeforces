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
	if (k > n){
		return cout << -1, 0;
	}
	if (k == n){
		return cout << "0 0", 0;
	}
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a, a + n);
	cout << a[n - k - 1] + 1 << ' ' << a[n - k - 1] + 1 << endl;
}