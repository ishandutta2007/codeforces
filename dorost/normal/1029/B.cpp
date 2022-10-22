#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	cin >> n;
	int a[n];
	bool f[n] = {};
	int mx = 0, ans = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (i == 0)
			continue;
		if (a[i] <= a[i - 1] * 2){
			f[i] = true;
		}
		if (f[i])
			ans ++;
		else
			ans = 0;
		mx = max(ans, mx);
	}
	cout << mx + 1;
}