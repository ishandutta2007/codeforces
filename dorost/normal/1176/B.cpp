/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int d[n], cnt[3] = {};
		for (int i = 0; i < n; i++){
			cin >> d[i];
			cnt[d[i] % 3] ++;
		}
		int a = cnt[1], b = cnt[2], c = cnt[0];
		int x = min(a, b);
		cout << c + max(x + (a - x) / 3 + (b - x) / 3, a / 3 + b / 3 + min(a % 3, b % 3)) << endl;
	}
}