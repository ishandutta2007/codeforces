/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1123;
int a[N], b[N];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort (a, a + n);
		int ans = -1;
		for (int i = 1; i <= 1024; i++){
			bool f = true;
			for (int j = 0; j < n; j++){
				b[j] = (a[j] ^ i); 
			}
			sort (b, b + n);
			for (int i = 0; i < n; i++){
				if (b[i] != a[i])
					f = false;
			}
			if (f){
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
}