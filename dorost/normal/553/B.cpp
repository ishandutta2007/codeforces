/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 51;
int fib[N];

void ans(int n, int k, int x) {
	if (n == 1) {
		cout << x;
		return;
	}
	if (n == 0) {
		return;
	}
	if (k <= fib[n - 1]) {
		cout << x << ' ';
		ans(n - 1, k, x + 1);
	} else {
		cout << x + 1 << ' ' << x << ' ';
		ans(n - 2, k - fib[n - 1], x + 2);
	}
}

int32_t main() {
	int n, k;
	cin >> n >> k;
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i < N; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	ans(n, k, 1);
}