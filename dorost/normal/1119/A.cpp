/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
int a[N];

int32_t main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int mx = 0;
	for (int i = 0; i < n; i++){
		if (a[i] != a[n - 1]){
			mx = max(mx, n - 1 - i);
		}
		if (a[i] != a[0]){
			mx = max(mx, i);
		}
	}
	cout << mx << endl;
}