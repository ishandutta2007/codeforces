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
	int n, s;
	cin >> n >> s;
	if (s - n + 1 <= n){
		cout << "NO\n";
	}else{
		cout << "YES\n";
		for (int i = 0; i < n; i++){
			cout << (i == 0 ? s - n + 1 : 1) << ' ';
		}
		cout << endl;
		cout << n << endl;
	}
}