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
		int n, x;
		cin >> n >> x;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		a[n] = 0;
		sort (a, a + n);
		reverse (a, a + n);
		int y = 1, ans = 0;
		for (int i = 0; i < n; i++){
			while (a[i] * y < x && i < n){
				i++;
				y++;
			}
			if (((a[i] * y) >= x))
				ans ++;// cout << t << ':' << i << ' ' << a[i] * y << endl;
			y = 1;
		}
		cout << ans << endl;
	}
}