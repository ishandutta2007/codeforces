/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], b[N];

int32_t main(){
	int n;
	cin >> n;
	for (int i =0 ; i < n;  i++){
		cin >> a[i];
	}
	b[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--){
		b[i] = a[i + 1] - -a[i];
	}
	for (int i = 0; i < n; i++)
		cout << b[i] << ' ';
}