/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int M = 998244353;

int32_t main(){
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++){
		string a;
		cin >> a;
		string t;
		for (int i = 1; i < a.size() * 2; i++){
			if (i % 2){
				t += a[i / 2];
			}else{
				t += '0';
			}
		}
		int x = stoll(t);
		x %= M;
		ans += x * 11 * n;
		ans %= M;
	}
	cout << ans;
}