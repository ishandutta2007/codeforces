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
	if (s.size() != t.size())
		return cout << "NO", 0;
	if (s == t)
		return cout << "YES", 0;
	int n = s.size();
	bool f = false, h = false;;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1')
			f = true;
	}
	for (int i = 0; i < n; i++) {
		if (t[i] == '1')
			h = true;
	}
	if (h && f) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}