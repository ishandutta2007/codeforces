/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
map <ld, int> mp;
ld x[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i < t; i++) {
		char ch;
		int a, b, c;
		cin >> ch >> a >> ch >> b >> ch >> ch >> c;
		x[i] = ((ld)a + 1.0 + (ld)b - 1.0) / (ld)c;
		mp[x[i]]++;
	}
	for (int i = 0; i < t; i++) {
		cout << mp[x[i]] << ' ';
	}
}