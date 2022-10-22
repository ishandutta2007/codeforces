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
		int a, b, c;
		cin >> a >> b >> c;
		if (a != 0 || b != 0){
			for (int i = 0; i < a + 1; i++)
				cout << '0';
			if (b % 2 == 0){
				for (int i = 0; i < b - 1; i++){
					cout << (i % 2 == 0 ? '1' : '0');
				}
			}else{
				for (int i = 0; i < b; i++){
					cout << (i % 2 == 0 ? '1' : '0');
				}
			}
			for (int i = 0; i < c; i++){
				cout << '1';
			}
			if (b % 2 == 0 && b != 0)
				cout << '0';
		}else{
			for (int i = 0; i < c + 1; i++)
				cout << '1';
		}
		cout << '\n';
	}
}