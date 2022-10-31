//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int n, l; cin >> n >> l;
		vector<long long> a(n + 2);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		a[0] = 0, a[n + 1] = l;
		vector<double> tmA(n + 2, 0), tmB(n + 2, 0);
		for (int i = 1; i <= n + 1; i++) {
			tmA[i] = tmA[i - 1] + (a[i] - a[i - 1]) * 1.0 / i;
		}
		for (int i = n; i >= 0; i--) {
			tmB[i] = tmB[i + 1] + (a[i + 1] - a[i]) * 1.0 / (n + 1 - i);
		}
		double st = 0.1, en = min(tmA[n + 1], tmB[0]);
		for (int step = 0; step < 100; step++) {
			double mid = (st + en) / 2;
			int p1 = lower_bound(tmA.begin(), tmA.begin() + n + 1, mid) - tmA.begin() - 1;
			int p2 = lower_bound(tmB.begin(), tmB.begin() + n + 1, mid, greater <double> ()) - tmB.begin();
			double dA = a[p1] + (p1 + 1) * (mid - tmA[p1]);
			double dB = a[p2] - (n - p2 + 2) * (mid - tmB[p2]);
			if (dA > dB) en = mid;
			else st = mid;
		}
		cout << fixed << setprecision(10) << st << "\n";
	}
	return 0;
}