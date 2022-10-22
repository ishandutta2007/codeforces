/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	map <char, int> mp;
	mp['Q'] = 9;
	mp['q'] = -9;
	mp['R'] = 5;
	mp['r'] = -5;
	mp['B'] = 3;
	mp['b'] = -3;
	mp['N'] = 3;
	mp['n'] = -3;
	mp['P'] = 1;
	mp['p'] = -1;
	string s[8];
	int an = 0;
	for (int i = 0; i < 8; i++){
		cin >> s[i];
		for (int j = 0; j < 8; j++){
			an += mp[s[i][j]];
		}
	}
	if (an == 0)
		cout << "Draw";
	else
		cout << (an < 0 ? "Black" : "White");
}