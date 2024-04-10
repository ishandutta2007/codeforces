/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool T (int x, int y){
	if (x < 0 || y < 0 || x > 7 || y > 7){
		return false;
	}
	return true;
}

int32_t main(){
	string s;
	cin >> s;
	int x = s[0] - 'a';
	int y = s[1] - '1';
	int ans = -1;
	for (int i = -1; i <= 1; i++){
		for (int j = -1; j <= 1; j++){
			if (T(x + i, y + j))
				ans ++;
		}
	}
	cout << ans;
}