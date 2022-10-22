/* 	* In the name of GOD 
 * Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	cin >> n;
	int a[n], mp[n * 2 + 1] = {};
	for (int i = 0; i < n; i++){
		cin >> a[i];
		mp[a[i]] ++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		if (mp[a[i]] < 2)
			continue;
		int mn = n, an = -1;
		for (int j = a[i]; j <= n * 2; j++){
			if (mp[j] == 0){
				if (abs(j - a[i]) < mn){
					mn = abs(j - a[i]);
					an = j;
				}
			}
		}
		//		cerr << i << ":" << mn << ' ' << an << endl;
		ans += mn;
		mp[a[i]] --;
		mp[an]++;
	}
	cout << ans << endl;
}