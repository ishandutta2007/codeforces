/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve (int n, int k){
	int x = k / n;
	int y = k % n;
	char c[n][n] = {};
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			c[i][j] = '0';
		}
	}
	for (int i = 0; i <= x; i++){
		for (int j = 0; j < n; j++){
			if (i == x && j >= y)
				continue;
			c[j][(j + i) % n] = '1';
		}
	}
	int a[n] = {}, b[n] = {};
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			a[i] += (c[i][j] == '1');
			b[j] += (c[j][i] == '1');
		}
	}
	int a1 = *max_element(a, a + n);
	int a2 = *min_element(a, a + n);
	int b1 = *max_element(b, b + n);
	int b2 = *min_element(b, b + n);
	cout << pow(a1 - a2, 2) + pow(b1 - b2, 2) << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << c[i][j];
		}
		cout << endl;
	}
}

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		solve(n, k);
	}
}