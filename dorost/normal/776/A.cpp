/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	string s, t;
	cin >> s >> t;
	cout << s << ' ' << t << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string a, b;
		cin >> a >> b;
		if (s == a)
			s = b;
		else
			t = b;
		cout << s << ' ' << t << endl;
	}
}