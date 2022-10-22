/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 301234;
int n;

bool check(int k) {
	int x = 0, y = n;
	while (y) {
		int f = min(k, y);
		y -= f;
		x += f;
		int s = y / 10;
		y -= s;
	}
	return (x >= (n + 1) / 2);
}

int bs (int k) {
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) { 
			r = mid;
		} else {
			l = mid + 1;  
		}
	}
	return l;
}

int32_t main() {
	cin >> n;
	cout << bs(n);
}