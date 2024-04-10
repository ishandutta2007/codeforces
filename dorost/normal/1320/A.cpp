#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int32_t n;
	cin >> n;
	int32_t a[n];
	int dp[n];
	ll mx = -1;
	bool f[n];
	pair <int, int> b[n];
	for (int32_t i = 0; i < n; i++){
		f[i] = true;
		cin >> a[i];
		b[i] = make_pair(a[i] - i, i);
		mx = max((ll)a[i], mx);
	}
	sort (b, b + n);
	ll sum = a[b[0].S];
	for (int i = 1; i < n; i++){
		if (b[i].F != b[i - 1].F){
			sum = a[b[i].S];
		}else{
			sum += a[b[i].S];
		}
		mx = max(sum, mx);
	}
	cout << mx;
}