#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[3], b[3];
	for (int i : {0, 1, 2}) {
		cin >> a[i];
	}
	for (int i : {0, 1, 2}) {
		cin >> b[i];
	}
	int maxa = 0;
	for (int i : {0, 1, 2}) {
		maxa += min(a[i], b[(i + 1) % 3]);
	}
	int mina = n;
	for (int i : {0, 1, 2}) {
		if (a[i] >= b[i] && a[(i + 1) % 3] >= b[(i + 1) % 3]) {
			mina = max(0, a[(i + 1) % 3] - b[i] - b[(i + 1) % 3]);
		}
		if (b[i] >= a[i] && b[(i + 1) % 3] >= a[(i + 1) % 3]) {
			mina = max(b[i] - a[i] - a[(i + 1) % 3], 0);
		}
	}
	cout << mina << ' ' << maxa << '\n';
	return 0;
}