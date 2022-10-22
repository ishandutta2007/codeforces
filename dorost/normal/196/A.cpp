/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

int32_t main() {
	string s;
	cin >> s;
	int n = s.size();
	a[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] >= s[a[i + 1]]) {
			a[i] = i;
		} else {
			a[i] = a[i + 1];
		}
	}
	int ans = 0, x = 0;
	while (x < n) {
		x = a[x] + 1;
		cout << s[x - 1];
	}
}