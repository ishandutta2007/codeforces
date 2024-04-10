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
		int n;
		cin >> n;
		if (n == 1){
			cout << "1" << endl;
			continue;
		}
		if (n == 2 || n == 3){
			cout << -1 << endl;
			continue;
		}
		if (n == 4){
			cout << "3 1 4 2\n";
			continue;
		}
		int i;
		for (i = 1; i <= n; i += 2){
			cout << i << ' ';
		}
		i -= 2;
		cout << i - 3 << ' ';
		if (n % 2 == 0)
			cout << i + 1 << ' ';
		cout << i - 1 << ' ';
		for (int j = i - 5; j > 0; j -= 2){
			cout << j << ' ';
		}
		cout << endl;
	}
}