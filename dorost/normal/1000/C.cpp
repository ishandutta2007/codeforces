/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
ll l[N], r[N], ans[N];
map <ll, int> mp;

int32_t main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		mp[l[i]]++;
		mp[r[i] + 1]--;
	}
	int a = 0;
	ll lst = -1;
	for (auto [x, y] : mp) {
		//cout << x << ' ' << y << ' ' << lst << ' ' << a << '\n';
		ans[a] += (lst == -1 ? 0 : x - lst);
		lst = x;
		a += y;
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
}