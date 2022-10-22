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
	int an = 0;
	int n = s.size();
	for (int i = 0; i < n; i++){
		if (s[i] == '0'){
			an = i;
			break;
		}
	}
	for (int i = 0; i < n; i++){
		if (i == an)
			continue;
		cout << s[i];
	}
}