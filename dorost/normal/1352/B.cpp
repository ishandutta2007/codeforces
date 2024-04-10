/*	* In the name of GOD
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
		int n, k;
		cin >> n >> k;
		if (n - (k - 1) > 0 && (n - (k - 1)) % 2){
			cout << "YES" << endl;
			for (int i = 0; i < k - 1; i++){
				cout << "1 ";
			}
			cout << n - (k - 1) << endl;
		}else if (n - ((k - 1) * 2) > 0 && (n - ((k - 1) * 2)) % 2 == 0){
			cout << "YES" << endl;
			for (int i = 0; i < k - 1; i++){
				cout << "2 ";
			}
			cout << n - ((k - 1) * 2) << endl;
		}else
			cout << "NO" << endl;
	}
}