/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
string t[24] = {
	"ABCD", "ABDC", "ACBD", "ACDB", "ADBC", "ADCB",
	"BACD", "BADC", "BCAD", "BCDA", "BDAC", "BDCA",
	"CABD", "CADB", "CBAD", "CBDA", "CDAB", "CDBA",
	"DABC", "DACB", "DBAC", "DBCA", "DCAB", "DCBA"};

int32_t main(){
	int n, m;
	cin >> n >> m;
	string s[n];
	int xa, ya, xb, yb;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		for (int j = 0; j < m; j++){
			if (s[i][j] == 'S')
				xa = i, ya = j;
			else if (s[i][j] == 'E')
				xb = i, yb = j;
		}
	}
	string r;
	cin >> r;
	int ans = 0;
	for (int k = 0; k < 24; k++){
		int x = xa, y = ya;
		bool f = true;
		for (int i = 0; i < r.size(); i++){
			char c = t[k][r[i] - '0'];
			if (c == 'A')
				x--;
			else if (c == 'B')
				x++;
			else if (c == 'C')
				y--;
			else
				y++;
			if (x < 0 || y < 0 || x >= n || y >= m)
				f = false;
			else if (s[x][y] == '#')
				f = false;
			if (x == xb && y == yb && f)
				break;
		}
		if (x == xb && y == yb && f)
			ans ++;
	}
	cout << ans << endl;
}