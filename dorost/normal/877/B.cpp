/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 5002;
int a[N];

int32_t main() {
	string s;
	cin >> s;
	int n = s.size();
	a[0] = 0;
	for (int i = 0; i < n; i++) {
		a[i + 1] = a[i] + (s[i] == 'a');
	}
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int x = a[i + 1] + a[n] - a[j];
			x += (j - i + 1) - (a[j + 1] - a[i]);
			mx = max(mx, x);
		}
	}
	cout << min(n, mx);
}