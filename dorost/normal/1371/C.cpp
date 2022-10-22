/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int a, b, n, m;
		cin >> a >> b >> n >> m;
		if (n + m > a + b){
			cout << "No\n";
			continue;
		}
		if (min(a, b) < m){
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
	}
}