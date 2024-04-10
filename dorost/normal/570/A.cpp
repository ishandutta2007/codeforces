/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long 

int32_t main(){
	int n, m;
	cin >> n >> m;
	int a[m][n], ans [n] = {};
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; i++){
		int x = max_element(a[i], a[i] + n) - a[i];
		ans [x]++;
	}
//	for (int i = 0; i < n; i++)
//		cerr << ans[i] << ' ';
//	cerr << endl;
	cout << max_element(ans, ans + n) - ans + 1;
}