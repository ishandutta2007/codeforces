/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++){
		if (i == 0 && s[i] == '9'){
			cout << 9;
			continue;
		}
		if (s[i] >= '5')
			cout << '9' - s[i];
		else
			cout << s[i];
	}
}