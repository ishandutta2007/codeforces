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
	pair <int, int> a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i].F, a[i].S = i + 1;
	sort (a, a + n);
	int ans = n, sum = 0;
	for (int i = 0; i < n; i++){
		sum += a[i].F;
		if (sum > k){
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	for (int i = 0; i < ans; i++){
		cout << a[i].S << ' ';
	}
}