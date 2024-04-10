/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	vector <int> v = {6, 10, 14, 15};
	int t = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n <= 30) {
			cout << "NO" << endl;
			continue;
		}
		if (n - 30 != 6 && n - 30 != 10 && n - 30 != 14) {
			cout << "Yes\n" << 6 << ' ' << 10 << ' ' << 14 << ' ' << n - 30 << endl;
		}else if (n - 31 != 6 && n - 30 != 11 && n - 31 != 15){
			cout << "Yes\n" << 6 << ' ' << 10 << ' ' << 15 << ' ' << n - 31 << endl;
		}
	}
}