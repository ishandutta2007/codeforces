/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	a--;
	b--;
	if (s[a] == s[b]){
		return cout << 0, 0;
	}
	cout << 1;
}