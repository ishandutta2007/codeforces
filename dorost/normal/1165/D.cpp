#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 321;
int a[N];

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, mx = 0, mn = 1000 * 10000;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			mx = max(mx, a[i]);
			mn = min(mn, a[i]);
		}
		int x = mn * mx, ans = 0;
		ld sq = sqrt(x);
		for (int i = 2; i < sq; i++){
			if (x % i == 0)
				ans += 2;
		}
//		cout << x << ' ' << sq << endl;
		int i = sq;
		if (i * i == x){
			ans ++;
		}
//		cout << ans << endl;
		if (n == ans){
			bool f = true;
			sort (a, a + n);
			for (int i = 0; i < n; i++){
				if (a[i] * a[n - i - 1] != x){
					f = false;
				}
			}
			if (f)
				cout << x << endl;
			else
				cout << -1 << endl;
		}else{
			cout << -1 << endl;
		}
	}
}