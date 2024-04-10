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
	int a[n], cnt[k] = {};
	for (int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i] - 1] ++;
	}
	int p = (n + 1) / 2, q = 0;
	for (int i = 0; i < k; i++){
		p -= cnt[i] / 2;
		q += cnt[i] % 2;
	}
	cout << n - (q - p);
}