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
	string s;
	int mx = 0;
	while (cin >> s){
		int num = 0;
		for (int i = 0; i < s.size(); i++) {
			num += isupper(s[i]);
		}
		mx = max(num, mx);
	}
	cout << mx;
}