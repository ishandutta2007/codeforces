/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main() {
	int n, cnt = 0, sum = 0, mx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mx = max(mx, x);
		sum += x;
		if (x % 2) 
			cnt++;
	}
	cout << (cnt % 2 == 0 && mx * 2 <= sum ? "YES" : "NO");
}