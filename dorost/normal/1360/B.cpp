/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
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
		int mn = 1000000;
		for (int i = 0; i < n - 1; i++){
			mn = min(mn, a[i + 1] - a[i]);
		}
		cout << mn << endl;
	}
}