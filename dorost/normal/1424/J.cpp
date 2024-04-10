/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012345;
bool f[N];
int psp[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	f[1] = true;
	for (int i = 2; i < N; i++) {
		if (f[i])
			continue;
		for (ll j = (ll)i * (ll)i; j < N; j += i) {
			f[j] = true;
		}
	}
	for (int i = 2; i < N; i++) {
		psp[i] = psp[i - 1] + (f[i] == 0);
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << psp[n] - psp[(int)floor(sqrt(n))] + 1 << '\n';
	}
}