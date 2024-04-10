/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 110;
string s[N];

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n, m, x, y, ans = 0, ans2 = 0;
		cin >> n >> m >> x >> y;
		for (int i = 0; i < n; i++){
			cin >> s[i];
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (s[i][j] == '.')
					ans ++;
			}
			for (int j = 0; j < m - 1; j++){
				if (s[i][j] == '.' && s[i][j + 1] == '.'){
					j++;
					ans2++;
				}
			}
		}
		cout << min(ans * x, (ans - (ans2 * 2)) * x + ans2 * y) << endl;
	}
}