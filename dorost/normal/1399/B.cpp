/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 105;
int a[N];
int b[N];
#define int long long

int32_t main(){
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) 
			cin >> a[i];
		for (int i = 0; i < n; i++) 
			cin >> b[i];
		int m = *min_element(a, a + n);
		int m2 = *min_element(b, b + n), ans = 0; // :|
		for (int i = 0; i < n; i++) {
			ans += max(a[i] - m, b[i] - m2);
		}
		cout << ans << endl;
	}
}