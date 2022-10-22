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
	int t = 1;
	cin >> t;
	while (t--) {
		int n, k, z, mx = 0;
		cin >> n >> k >> z;
		for (int i = 0; i < n; i++) 
			cin >> a[i];
		a[n] = 0;
		for (int i = 0; i <= z; i++) {
			vector <int> v;
			int sum = 0;
			int mx2 = 0;
			for (int j = 0; j <= k - i * 2; j++)
				mx2 = max(mx2, a[j] + a[j + 1]), sum += a[j];
			sum += mx2 * (i);
			mx = max(mx, sum);
		}
		cout << mx << endl;
	}
}