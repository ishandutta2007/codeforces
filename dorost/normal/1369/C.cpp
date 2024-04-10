/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], w[N];
vector <int> v;

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort (a, a + n);
		int ans = 0;
		int y = n - 1;
		for (int i = 0; i < k; i++){
			cin >> w[i];
			if (w[i] == 1){
				ans += a[y];
				y--;
			}
		}
		sort (w, w + k);
		reverse (w, w + k);
		int x = 0;
		for (int i = 0; i < k; i++){
			if (w[i] == 1)
				continue;
			ans += a[x];
//			cout << x << ' ';
			x += w[i] - 1;
		}
		for (int i = n - 1; i >= n - k; i--){
			ans += a[i];
//			cout << i << ' ';
		}
//		cout << endl;
		cout << ans << endl;
	}
}