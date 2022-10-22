/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, m, k;
	cin >> n >> m >> k;
	int a[m + 2] = {}, b[m + 2][n] = {};
	for (int i = 0; i <= m; i++){
		cin >> a[i];
		int x = a[i];
		for (int j = 0; j < n; j++){
			b[i][j] = x % 2;
			x /= 2;
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++){
		int an = 0;
		for (int j = 0; j < n; j++){
			if (b[i][j] != b[m][j])
				an ++;
		}
		if (an <= k)
			ans ++;//, cerr << i << endl;
	}
	cout << ans;
}