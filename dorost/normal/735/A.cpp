/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, k;
	string s;
	cin >> n >> k >> s;
	int g, t;
	for (int i = 0; i < n; i++){
		if (s[i] == 'G')
			g = i;
		if (s[i] == 'T')
			t = i;
	}
	if (abs(g - t) % k){
		return cout << "NO", 0;
	}
	bool f = true;
	for (int i = min(g, t) + k; i < max(g, t); i += k){
		if (s[i] == '#')
			f = false;
	}
	cout << (f ? "YES" : "NO");
}