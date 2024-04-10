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
	int in = 0;
	for (int i = 0; i < t.size(); i++){
		if (t[i] == s[in])
			in ++;
	}
	cout << min((int)s.size(), in + 1);
}