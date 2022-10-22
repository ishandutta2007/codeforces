/* 	* In the name of GOD 
	* Thanks God */
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int a[N];

int32_t main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	while (true) {
		bool f = false;
		for (int i = 0; i < n; i++) {
			if ((i == n - 1 || a[i] != a[i + 1]) && a[i] != k) {
				a[i]++;
				if (!f)
					ans++;
				f = true;
			}
		}
		if (!f)
			break;
	}
	cout << ans;
}