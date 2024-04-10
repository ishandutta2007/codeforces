#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main(){
	int n, m;
	cin >> n >> m;
	char c[n][m];
	bool a[n][m];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			a[i][j] = false;
		}
	}
	for (int i = 0; i < n; i++){
		bool f = true;
		for (int j = 0; j < m; j++){
			cin >> c[i][j];
			if (c[i][j] == 'S'){
				f = false;
			}
		}
		if (f){
			for (int j = 0; j < m; j++){
				a[i][j] = true;
			}
		}
	}
	for (int i = 0; i < m; i++){
		bool f = true;
		for (int j = 0; j < n; j++){
			if (c[j][i] == 'S'){
				f = false;
			}
		}
		if (f){
			for (int j = 0; j < n; j++){
				a[j][i] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (a[i][j]){
				ans ++;
			}
		}
	}
	cout << ans;
}