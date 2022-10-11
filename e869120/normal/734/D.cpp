#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long x[1000000], y[1000000], n, gx, gy; char f[1000000];
int main() {
	cin >> n >> gx >> gy;
	for (long long i = 0; i < n; i++) {
		cin >> f[i] >> x[i] >> y[i]; x[i] -= gx; y[i] -= gy;
	}
	gx = 0; gy = 0; long long maxn = 2100000000000; bool OK = false;
	for (long long i = 0; i < n; i++) { if (x[i] != 0 || y[i] < 0)continue; maxn = min(maxn, abs(y[i])); }
	for (long long i = 0; i < n; i++) { if (x[i] == 0 && y[i] == maxn && (f[i] == 'R' || f[i] == 'Q'))OK = true; }
	maxn = 2100000000000;
	for (long long i = 0; i < n; i++) { if (x[i] != 0 || y[i] > 0)continue; maxn = min(maxn, abs(y[i])); }
	for (long long i = 0; i < n; i++) { if (x[i] == 0 && y[i] == -maxn && (f[i] == 'R' || f[i] == 'Q'))OK = true; }
	maxn = 2100000000000;
	for (long long i = 0; i < n; i++) { if (x[i] < 0 || y[i] != 0)continue; maxn = min(maxn, abs(x[i])); }
	for (long long i = 0; i < n; i++) { if (x[i] == maxn && y[i] == 0 && (f[i] == 'R' || f[i] == 'Q'))OK = true; }
	maxn = 2100000000000;
	for (long long i = 0; i < n; i++) { if (x[i] > 0 || y[i] != 0)continue; maxn = min(maxn, abs(x[i])); }
	for (long long i = 0; i < n; i++) { if (x[i] == -maxn && y[i] == 0 && (f[i] == 'R' || f[i] == 'Q'))OK = true; }
	maxn = 2100000000000;
	for (long long i = 0; i < n; i++) { if (x[i] + y[i] != 0 || y[i] < 0)continue; maxn = min(maxn, abs(y[i])); }
	for (long long i = 0; i < n; i++) { if (x[i] + y[i] == 0 && y[i] == maxn && (f[i] == 'B' || f[i] == 'Q'))OK = true; }
	maxn = 2100000000000;
	for (long long i = 0; i < n; i++) { if (x[i] + y[i] != 0 || y[i] > 0)continue; maxn = min(maxn, abs(y[i])); }
	for (long long i = 0; i < n; i++) { if (x[i] + y[i] == 0 && y[i] == -maxn && (f[i] == 'B' || f[i] == 'Q'))OK = true; }
	maxn = 2100000000;
	for (long long i = 0; i < n; i++) { if (x[i] < 0 || x[i] - y[i] != 0)continue; maxn = min(maxn, abs(x[i])); }
	for (long long i = 0; i < n; i++) { if (x[i] == maxn && x[i] - y[i] == 0 && (f[i] == 'B' || f[i] == 'Q'))OK = true; }
	maxn = 2100000000;
	for (long long i = 0; i < n; i++) { if (x[i] > 0 || x[i] - y[i] != 0)continue; maxn = min(maxn, abs(x[i])); }
	for (long long i = 0; i < n; i++) { if (x[i] == -maxn && x[i] - y[i] == 0 && (f[i] == 'B' || f[i] == 'Q'))OK = true; }
	if (OK == true)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}