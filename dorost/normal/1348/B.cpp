#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 105;
int a[N];
bool f[N];

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		int mx = 0;
		for (int i = 0; i < n + 1; i++)
			f[i] = false;
		for (int i =0 ; i < n; i++){
			cin >> a[i];
			f[a[i]] = true;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++){
			if (f[i])
				ans ++;
		}
		if (ans > k){
			cout << -1 << endl;
			continue;
		}
		cout << n * k << endl;
		for (int i = 0; i < n; i++){
			for (int j = 1; j <= n; j++){
				if (f[j])
					cout << j << ' ';
			}
			for (int j = 0; j < k - ans; j++){
				cout << 1 << ' ';
			}
		}
		cout << endl;
	}
}