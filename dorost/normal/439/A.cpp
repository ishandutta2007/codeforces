/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, d;
	cin >> n >> d;
	int a[n];
	int sum = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i], sum += a[i];
	if (sum + (n - 1) * 10 > d)
		cout << -1;
	else
		cout << (d - sum) / 5;
}