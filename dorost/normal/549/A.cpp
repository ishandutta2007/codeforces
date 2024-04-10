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
	int ans = 0;
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < m - 1; j++){
			string t = "";
			t += s[i][j];
			t += s[i + 1][j];
			t += s[i + 1][j + 1];
			t += s[i][j + 1];
			sort (t.begin(), t.end ());
			if (t == "acef")
				ans ++;
		}
	}
	cout << ans << endl;
}