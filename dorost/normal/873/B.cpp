/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

int32_t main() {
	string s;
	int n;
	cin >> n >> s;
	int x = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			x--;
		else
			x++;
		a[x + n] = i + 1;
	}
	x = 0;
	int mx = a[n];
	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			x--;
		else
			x++;
		mx = max(mx, a[n + x] - i - 1);
	}
	cout << mx;
}