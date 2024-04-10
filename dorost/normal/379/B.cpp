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
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		for (int j = 0; j < x; j++){
			cout << "P";
			if (j != x - 1){
				if (i == 0)
					cout << "RL";
				else
					cout << "LR";
			}
		}
		if (i != n - 1)
			cout << 'R';
	}
}