/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, d;
	cin >> n >> d;
	string s;
	cin >> s;
	int x = 0, ans = 0;
	while (x != n - 1){
		int y = x;
		for (int i = x + 1; i < n; i++){
			if (i - y <= d && s[i] == '1')
				x = i;
		}
		ans ++;
		if (x == y)
			return cout << -1, 0;
	}
	cout << ans << endl;
}