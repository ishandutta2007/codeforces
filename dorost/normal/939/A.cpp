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
	for (int i =0 ; i < n; i++)
		cin >> a[i], a[i]--;
	int ans = 0;
	for (int i = 0; i < n; i++){
		if (a[a[a[i]]] == i)
			ans ++;
	}
	cout << (ans ? "Yes" : "No");
}