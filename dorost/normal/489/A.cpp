/* 	* In the name of GOD 
	a* Thanks God */
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
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << n << endl;
	for (int i = 0; i < n; i++){
		int ind = i;
		for (int j = i + 1; j < n; j++){
			if (a[j] < a[ind]){
				ind = j;
			}
		}
		swap(a[i], a[ind]);
		cout << i << ' ' << ind << endl;
	}
	for (int i = 0; i < n; i++){
		cerr << a[i] << ' ';
	}
}