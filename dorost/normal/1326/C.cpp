#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;
#define int long long
const int mod = 998244353;

int32_t main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	pair <int, int> a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i].F;
		a[i].S = i;
	}
	sort (a, a + n);
	reverse (a, a + n);
	vector <pair<int , int>> v;
	for (int i = 0; i < k; i++){
		v.push_back({a[i].S, a[i].F});
	}
	sort (v.begin(), v.end());
	int sum = v[0].S, mul = 1;
	for (int i = 1; i < k; i++){
		sum += v[i].S;
		mul *= (v[i].F - v[i - 1].F) % mod;
		mul %= mod;
	}
	cout << sum << ' ' << mul;
}