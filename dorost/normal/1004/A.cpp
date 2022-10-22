#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort (a, a + n);
	int ans = 0;
	for (int i = 0; i < n - 1; i++){
		if ((abs(a[i] - a[i + 1])) == 2 * k)
			ans ++;
		else if (abs (a[i] - a[i + 1]) > 2 * k)
			ans += 2;
	}
	cout << ans + 2 << endl;
//	for (auto x : st)
//		cout << x << ' ';
}