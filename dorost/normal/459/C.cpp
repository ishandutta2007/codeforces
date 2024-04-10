/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1023;
int a[N][N];

int32_t main(){
	int n, d, k;
	cin >> n >> k >> d;
	if (n > 1 && (k == 1))
		return cout << -1, 0;
	if (d == 1) {
		if (k < n) {
			return cout << -1, 0;
		}
		for (int i = 0; i < n; i++)
			cout << i + 1 << ' ';
		return 0;
	}
	if (n == 1) {
		for (int i = 0; i < d; i++) {
			cout << "1\n";
		}
		return 0;
	}
	int t = 1;
	for (int i = 0; i < d; i++) {
		t *= k;
		if (t >= n)
			break;
	}
	if (t < n) 
		return cout << -1, 0;
	for (int i = 0; i < n; i++) {
		int x = i;
		int f[d];
		for (int i = 0; i < d; i++) {
			f[i] = x % k + 1;
			x /= k;
		}
		for (int j = 0; j < d; j++) {
			a[j][i] = f[j];
		}
	}
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
}