/* 	* In the name of GOD 
 	* Thanks God */
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 301234;
int a[N], b[N], psra[N], psla[N], psrb[N], pslb[N], psa[N], psb[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		psra[i] = (i == 0 ? 0 : psra[i - 1] + a[i] * i);
		psrb[i] = (i == 0 ? 0 : psrb[i - 1] + b[i] * i);
	}
	for (int i = n - 1; i >= 0; i--) {
		psla[i] = (i == n - 1 ? 0 : psla[i + 1] + a[i] * (n - i - 1));
		pslb[i] = (i == n - 1 ? 0 : pslb[i + 1] + b[i] * (n - i - 1));
	}
	for (int i = 0; i < n; i++) {
		psa[i] = (i == 0 ? a[i] : psa[i - 1] + a[i]);
		psb[i] = (i == 0 ? b[i] : psb[i - 1] + b[i]);
	}
	int x = 0;
	int mx = psra[n - 1] + pslb[0] + psb[n - 1] * (n);
	for (int i = 0; i < n; i++) {
		if (i % 2) {
			x += b[i] * i * 2;
			x += a[i] * (i * 2 + 1);
			mx = max(mx, x + psra[n - 1] - psra[i] + ((psa[n - 1] - psa[i]) * (i * 2 + 1 - i)) + pslb[i + 1] + ((psb[n - 1] - psb[i]) * (i * 2 + 1 + n - i)));
		} else {
			x += a[i] * i * 2;
			x += b[i] * (i * 2 + 1);
			mx = max(mx, x + psrb[n - 1] - psrb[i] + ((psb[n - 1] - psb[i]) * (i * 2 + 1 - i)) + psla[i + 1] + ((psa[n - 1] - psa[i]) * (i     * 2 + 1 + n - i)));
		}
	}
	cout << mx;
}