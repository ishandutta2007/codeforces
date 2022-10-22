/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 10123456;
int ans[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	for (int i = 1; i * i < N; i++) {
		for (int j = i * i; j < N; j += i * i) {
			ans[j] = j / (i * i);
		}
	}
	int l, r;
	cin >> l >> r;
	r = l + r - 1;
	ll sum = 0;
	for (int i = l; i <= r; i++) 
		sum += ans[i];
	cout << sum;
}