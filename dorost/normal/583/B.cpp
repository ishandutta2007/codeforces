/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	cin >> n;
	int a[n + 10];
	bool f[n + 10];
	for (int i = 0; i < n; i++){
		cin >> a[i];
		f[i] = true;
	}
	int poi = 0;
	for (int i = 0; i < n; i++){
		if (i % 2 == 0){
			for (int j = 0; j < n; j++){
				if (a[j] <= poi && f[j])
					poi ++, f[j] = false; //, cerr << i << ' ' << j << ' ' << a[j] << ' ' << poi << '\n';
			}
		}else{
			for (int j = n - 1; j >= 0; j--){
				if (a[j] <= poi && f[j])
					poi ++, f[j] = false; //, cerr << i << ' ' << j << ' ' << a[j] << ' ' << poi << '\n';
			}
		}
		if (poi == n){
			cout << i;
			break;
		}
	}
}