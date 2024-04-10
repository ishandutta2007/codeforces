/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		vector <int> v;
		for (int i = 1; i * i <= n; i++){
			if (n % i)
				continue;
			v.push_back(i);
			if (i != n / i){
				v.push_back (n / i);
			}
		}
		int mx = 0;
		for (int i = 0; i < v.size(); i++){
			if (v[i] > k)
				continue;
			mx = max(mx, v[i]);
		}
		cout << n / mx << endl;
	}
}