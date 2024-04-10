#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 200000;
const int M = 100;
int mp[M], a[N];

int32_t main(){
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		mp[a[i] % k] ++;
	}
	int ans = 0;
	for (int i = 1; i < (k + 1) / 2; i++){
		ans += min(mp[i] , mp[k - i]);
	}
	ans += mp[0] / 2;
	if (k % 2 == 0){
		ans += mp[k / 2] / 2;
	}
	cout << ans * 2;
}