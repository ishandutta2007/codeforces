/* 	* In the name of GOD 
 	* Thanks God */
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
		int n;
		cin >> n;
		int cnt[5] = {};
		for (int i = 2; i <= 3; i++){
			while (n % i == 0)
				n /= i, cnt[i] ++;
		}
		if (n != 1 || cnt[2] > cnt[3]){
			cout << -1 << ' ';
			continue;
		}
		cout << cnt[3] * 2 - cnt[2] << ' ';
	}
}