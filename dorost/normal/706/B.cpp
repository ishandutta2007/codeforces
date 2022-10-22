#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int n, x;
	cin >> n;
	int f[1000001] = {};
	for (int i = 0; i < n; i++){
		cin >> x;
		f[x]++;
	}
	int q, dp = 0;
	cin >> q;
	pair <int, int> m[q];
	int ans[q];
	for (int i = 0; i < q; i++){
		cin >> m[i].F;
		if (m[i].F > 1000000)
			m[i].F = 1000000;
		m[i].S = i;
	}
	sort (m, m + q); 
	for (int i = 0; i <= m[0].F; i++){
		dp += f[i];
	}
	ans[m[0].S] = dp;
	for (int i = 1; i < q; i++){
		for (int j = m[i - 1].F + 1; j <= m[i].F; j++){
			dp += f[j];
		}
		ans[m[i].S] = dp;
	}
	for (int i = 0; i < q; i++){
		cout << ans[i] << endl;
	}
}