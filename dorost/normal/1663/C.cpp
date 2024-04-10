/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101;
int a[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i], sum += a[i];
	cout << sum;
}