/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long 
const int N = 14923456;
int a[N];

int32_t main(){
	int x = 0;
	for (int i = 0; i < N; i++){
		a[i] = x;
		x += (i + 1);
	}
//	cout << a[N - 1];
	int n;
	cin >> n;
	int an = 0;
	for (int i = 0; i < N; i++){
		if (a[i] < n){
			an = a[i];
//			cout << an << ' '; 
		}
	}
	cout << n - an;
}