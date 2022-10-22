/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, p, k;
		cin >> n >> p >> k;
		int p1 = p, mx = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort (a, a + n);
		p1 -= a[0];
		if (p1 < 0){
			cout << mx << endl;
			continue;
		}
		mx = 1;
		for (int i = 2; i < n; i += 2){
			p1 -= a[i];
			if (p1 < 0){
				break;
			}
			mx += 2;
		}
		int mx1 = 0;
		for (int i = 1; i < n; i += 2){
			p -= a[i];
			if (p < 0){
				break;
			}
			mx1 += 2;
		}
		cout << max(mx, mx1) << endl;
	}
}