/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	string s, t;
	cin >> s >> t;
	int n = s.size();
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1')
			x++;
	}
	int m = t.size();
	for (int i = 0; i < m; i++) {
		if (t[i] == '1')
			y++;
	}
	cout << ( (x >= y) ? "YES" : (y == x + 1 && (x % 2) ? "YES" : "NO"));
}