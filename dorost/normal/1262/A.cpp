#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, mx = 0, mn = 1000000001;
		cin >> n;
		for (int i = 0; i < n; i++){
			int l, r;
			cin >> l >> r;
			mx = max(mx, l);
			mn = min(mn, r);
		}
		if (mx > mn)
			cout << mx - mn;
		else
			cout << 0;
		cout << endl;
	}
}