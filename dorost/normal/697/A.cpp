/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t, s, x;
	cin >> t >> s >> x;
	int d = abs (t - x);
	if (x < t){
		cout << "No";
	}else if (x == t + 1){
		cout << "No";
	}else if (d % s < 2)
		cout << "Yes";
	else
		cout << "No";
}