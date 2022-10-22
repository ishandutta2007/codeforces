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
		string s;
		cin >> s;
		int mn = 100000;
		int n = s.size();
		int a = 0, b = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '1')
				b++;
		for (int i = 0; i < n; i++){
			a += (s[i] == '0');
			b -= (s[i] == '1');
			mn = min(mn, a + b);
		}
		a = 0, b = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '0')
				b++;
		for (int i = 0; i < n; i++){
			a += (s[i] == '1');
			b -= (s[i] == '0');
			mn = min(mn, a + b);
		}
		cout << mn << endl;
	}
}