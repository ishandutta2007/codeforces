/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, x;
		cin >> n >> x;
		int sum = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i], sum += a[i];
		if (sum % x){
			cout << n << endl;
			continue;
		}
		int mx = 0;
		int d = 0;
		for (int i = 0; i < n; i++){
			d += a[i];
			if (d % x){
				mx = max(mx, i + 1); 
			}
		}
		d = 0;
		for (int i = n - 1; i >= 0; i--){
			d += a[i];
			if (d % x){
				mx = max(mx, n - i);
			}
		}
		if (mx == 0){
			mx = -1;
		}
		cout << mx << endl;
	}
}