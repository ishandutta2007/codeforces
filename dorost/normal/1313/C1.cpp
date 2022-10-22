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
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int ans[n];
	int mx = -1;
	for (int i = 0; i < n; i++){
		int b[n];
		int sum = 0;
		int mn = a[i];
		b[i] = a[i];
		for (int j = i + 1; j < n; j++){
			mn = min(mn, a[j]);
			b[j] = mn;
		}
		mn = a[i];
		for (int j = i - 1; j >= 0; j--){
			mn = min(mn, a[j]);
			b[j] = mn;
		}
		for (int j = 0; j < n; j++){
			sum += b[j];
		}
		if (sum > mx){
			mx = sum;
			for (int j = 0; j < n; j++){
				ans[j] = b[j];
			}
		}
	}
	for (int i = 0; i < n; i++){
		cout << ans[i] << ' ';
	}
}