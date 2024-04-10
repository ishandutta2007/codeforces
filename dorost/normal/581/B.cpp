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
	int a[n], dp[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	dp[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--){
		dp[i] = max(a[i], dp[i + 1]);
	}
	for (int i = 0; i < n; i++){
		if (i == n - 1)
			cout << 0 << endl;
		else
			cout << (dp[i] == a[i] ? max(0, dp[i + 1] - a[i] + 1) : dp[i] - a[i] + 1) << ' ';
	}
}