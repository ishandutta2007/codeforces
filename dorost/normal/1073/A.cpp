/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	string s;
	cin >> n >> s;
	char c = s[0];
	bool f = false;
	for (int i = 1; i < n; i++){
		if (c != s[i])
			f = true;
	}
	if (!f)
		return cout << "NO", 0;
	cout << "YES\n";
	for (int i = 0; i < n - 1; i++){
		if (s[i] != s[i + 1]){
			cout << s[i] << s[i + 1];
			return 0;
		}
	}
}