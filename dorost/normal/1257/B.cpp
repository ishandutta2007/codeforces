/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		if (n == 1){
			if (m == 1){
				cout << "yes" << endl;
			}else
				cout << "no" << endl;
		}else if (n == 2 || n == 3){
			if (m == 1 || m == 2 || m == 3){
				cout << "yes" << endl;
			}else
				cout << "no" << endl;
		}else
			cout << "yes" << endl;
	}
}