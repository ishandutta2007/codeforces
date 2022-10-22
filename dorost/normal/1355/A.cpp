/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int a, k;
		cin >> a >> k;
		k--;
		while (k--){
			string s = to_string(a);
			char mn = '9', mx = '0';
			for (int i = 0; i < s.size(); i++){
				mn = min(mn, s[i]);
				mx = max(mx, s[i]);
			}
			if (mn == '0')
				break;
			mx -= '0';
			mn -= '0';
			a += mn * mx;
		}
		cout << a << endl;
	}
}