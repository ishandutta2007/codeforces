/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		map <ll, ll> mp;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (a[i] % k == 0)
				a[i] = k;
			else
				a[i] %= k;
			mp [k - a[i]] ++;
		}
		ll all = 0;
		for (auto x : mp){
			if (x.F == 0)
				continue;
			all = max(all, (x.S - 1) * k + x.F + 1);
		}
		cout << all << ' ';
	}
}