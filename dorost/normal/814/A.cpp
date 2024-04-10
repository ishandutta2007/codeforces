/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, k;
	cin >> n >> k;
	int ans = 0, an = 0;
	int a[n], b[k];
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] == 0)
			ans++;
	}
	for (int i = 0; i < k; i++){
		cin >> b[i];
		if (b[i] == 0)
			ans ++;
		else
			an ++;
	}
	if (ans != k){
		return cout << "No", 0;
	}
	if (an > 1){
		return cout << "Yes", 0;
	}
	if (an == 0){
		return cout << (is_sorted(a, a + n) ? "No" : "Yes"), 0;
	}
	if (an == 1){
		int x;
		for (int i = 0; i < k; i++){
			if (b[i]){
				x = b[i];
			}
		}
		for (int i = 0; i < n; i++){
			if (a[i] == 0)
				a[i] = x;
		}	
		return cout << (is_sorted(a, a + n) ? "No" : "Yes"), 0;
	}
}