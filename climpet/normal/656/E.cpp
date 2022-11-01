#include <bits/stdc++.h>
using namespace std;

#def\
ine F fo\
r

int a[10][10];

int main(){
	int n;
	cin >> n;
	F(int i = 0; i < n; ++i)
	F(int j = 0; j < n; ++j){
		cin >> a[i][j];
	}
	
	F(int k = 0; k < n; ++k)
	F(int i = 0; i < n; ++i)
	F(int j = 0; j < n; ++j){
		a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	}
	
	int ans = 0;
	F(int i = 0; i < n; ++i)
	F(int j = 0; j < n; ++j){
		ans = max(ans, a[i][j]);
	}
	
	cout << ans << endl;
}