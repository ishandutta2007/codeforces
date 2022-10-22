/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, m;
	cin >> n >> m;
	string s[n];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	bool f = true;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m - 1; j++){
			if (s[i][j] != s[i][j + 1])
				f = false;
		}
	}
	for (int i = 0; i < n - 1; i++){
		if (s[i][0] == s[i + 1][0])
			f = false;
	}
	cout << (f ? "YES" : "NO");
}