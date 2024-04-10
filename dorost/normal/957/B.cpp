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
	for (int i =0 ; i < n; i++)
		cin >> s[i];
	bool f = true;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			for (int jj = 0; jj < m; jj ++){
				for (int iii = 0; iii < n; iii ++){
					if (s[i][j] == '#' && s[i][jj] == '#' && s[iii][j] == '#' && s[iii][jj] == '.')
						f = false;
				}
			}
		}
	}
	cout << (f ? "Yes" : "No");
}