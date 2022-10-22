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
		vector <int> v;
		int i = 0;
		while (n){
			if (n % 10)
				v.push_back(n % 10 * pow(10, i));
			n /= 10;
			i++;
		}
		cout << v.size() << '\n';
		for (int i = 0; i < v.size(); i++){
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
}