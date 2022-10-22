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
	cin >> n;
	string s [n];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int ans = 0;
	for (int i = 1; i < n - 1; i++){
		for (int j = 1; j < n - 1; j++){
			if (s[i][j] == 'X' && s[i + 1][j + 1] == 'X' && s[i + 1][j - 1] == 'X' && s[i - 1][j + 1] == 'X' && s[i - 1][j - 1] == 'X')
				ans ++;
		}
	}
	cout << ans;
}