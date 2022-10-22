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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		int n = s.size();
		int a = 0, ans = 0;
		int x = 0;
		for (int i = 0; i < n; i++){
			if (s[i] == '-')
				a--;
			else
				a++;
			if ((x + a) == -1){
				ans += -(x + a);
				x += -(x + a);
				ans += (i);
			}
			ans ++;
		}
		cout << ans << endl;
	}
}