/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i <= 1000; i++){
		for (int j = 0; j <= 1000; j++){
			if (i * i + j == n && j * j + i == m)
				ans ++;
		}
	}
	cout << ans << endl;
}