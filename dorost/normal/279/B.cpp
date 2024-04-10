/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], ps[N];

int32_t main(){
	int n, t;
	cin >> n >> t;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] == 0)
			ps[i] = a[i];
		else
			ps[i] = ps[i - 1] + a[i];
	}
	int mx = 0;
	for (int i = 0; i < n; i++){
		int y = upper_bound (ps, ps + n, ps[i] + t) - ps - i - 1;
		mx = max (mx, y);
	}
	if (ps[n - 1] <= t)
		mx = n;
	cout << mx;
}