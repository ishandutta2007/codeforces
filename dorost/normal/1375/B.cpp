/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 302;
int  s[N][N], t[N][N];

int32_t main(){
	int tt = 1;
	cin >> tt;
	while (tt--){
		int n, m;
		cin >> n >> m;
		for (int i =0 ; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> s[i][j];
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if ((i == 0 && j == 0) || (i == n - 1 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == m - 1)){
					t[i][j] = 2;
				}else if (i == 0 || i == n - 1 || j == 0 || j == m - 1){
					t[i][j] = 3;
				}else{
					t[i][j] = 4;
				}
			}
		}
		bool f = true;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (s[i][j] > t[i][j])
					f = false;
			}
		}
		if (f){
			cout << "Yes\n";
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					cout << t[i][j] << ' ';
				}	
				cout << endl;
			}
		}else{
			cout << "No\n";
		}
	}
}