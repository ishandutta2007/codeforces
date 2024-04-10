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

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) 
			cin >> a[i];
		int ans = n - 1;
		for (int i = n - 2; i >= 0; i--){
			if (a[i] < a[i + 1])
				break;
			ans = i;
		}
		int an = max (0, ans - 1);
		for (int i = ans - 1; i >= 0; i--){
			if (a[i] > a[i + 1])
				break;
			an = i;
		}
		cout << an << endl;
	}
}