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
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort (a, a + n);
		int mx = 0;
		for (int i = 0; i < n; i++){
			if (a[i] <= i + 1){
				mx = max(mx, i + 1);
			}
		}
		cout << mx + 1 << endl;
	}
}