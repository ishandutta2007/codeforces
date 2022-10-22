/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 40;
int a[N][N];

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		if (n == 2 && m == 2){
			if (a[0][0] != a[1][1])
				cout << 1 << endl;
			else
				cout << 0 << endl;
			continue;
		}
		int ans = 0;
		for (int k = 0; k < (n + m - 1) / 2; k++){
			if ((n + m) % 2 == 0 && k == (n + m - 2) / 2)
				continue;
			int an1 = 0, an2 = 0;
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					if ((i + j) != k){
						continue;
					}
					if (a[i][j] == 1)
						an1++;
					else
						an2++;
					if (a[n - i - 1][m - j - 1] == 1)
						an1++;
					else
						an2++;
				}
			}
			ans += min(an1, an2);
		}
		cout << ans << endl;
	}
}