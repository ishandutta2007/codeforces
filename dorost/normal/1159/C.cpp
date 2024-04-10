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
	int n, m;
	cin >> n >> m;
	int a[n], b[m], sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum1 += a[i];
	}
	for (int i = 0; i < m; i++){
		cin >> b[i];
		sum2 += b[i];
	}
	sort (a, a + n);
	sort (b, b + m);
	if(a[n - 1] > b[0]){
		cout << -1;
	}else if(a[n - 1] == b[0]){
		cout << sum1 * m + (sum2 - (a[n - 1] * m));
	}else{
		cout << sum1 * m + (sum2 - (a[n - 1] * (m - 1))) - a[n - 2];
	}
}