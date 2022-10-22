/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1002, M = 201234;
int a[N], ans[M];

int32_t main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < i; j++) {
			ans[a[j] + a[i]]++;
		}
	}
	int mx = 0;
	for (int i = 0; i < M; i++) {
		mx = max(mx, ans[i]);
	}
	cout << mx;
}