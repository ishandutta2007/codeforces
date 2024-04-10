/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		int a[n][m];
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				bool f = true;
				for (int k = 0; k < n; k++){
					if (a[k][j] == 1)
						f = false;
				}
				for (int k = 0; k < m; k++){
					if (a[i][k] == 1)
						f = false;
				}
				if (f){
					a[i][j] = 1;
					ans ++;
				}
			}
		}
		cout << (ans % 2 ? "Ashish" : "Vivek") << endl;
	}
}