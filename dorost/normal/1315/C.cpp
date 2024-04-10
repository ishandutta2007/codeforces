#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

signed main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		bool f = false, h = true, d = true;
		int ans[n * 2];
		bool x[n * 2 + 1] = {};
		for (int i = 0; i < n; i++){
			cin >> a[i];
			x[a[i]] = true;
		}
		for (int i = 0; i < n; i++){
			int g = -1;
			for (int j = a[i] + 1; j <= 2 * n; j++){
				if (x[j] == false){
					g = j;
					x[j] = true;
					break;
				}
			}
			ans[i * 2] = a[i];
			ans[i * 2 + 1] = g;
		}
		if (d){
			int v[2 * n];
			for (int i = 0; i < 2 * n; i++){
				v[i] = ans[i];
			}
			sort(v, v + n * 2);
			bool g = true;
			for (int i = 1; i <= 2 * n; i++){
				if (v[i - 1] != i){
					g = false;
					break;
				}
			}
			for (int i = 0; i < n * 2; i += 2){
				if (min(ans[i], ans[i + 1]) != a[i / 2]){
					g = false;
					break;
				}
			}
			if (g == false){
				cout << "-1" << endl;
			}else{
				for (int i = 0; i < 2 * n; i++){
					cout << ans[i] << ' ';
				}	
				cout << endl;
			}
		}
	}	
}