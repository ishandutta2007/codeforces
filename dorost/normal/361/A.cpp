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
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j)
				cout << k << ' ';
			else
				cout << 0 << ' ';
		}
		cout << endl;
	}
}