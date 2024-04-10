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
	int a[n], a1, an;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] == 1)
			a1 = i + 1;
		if (a[i] == n)
			an = i + 1;
	}
	cout << max({n - a1, an - 1, a1 - 1, n - an});
}