#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int root (int n) {
	n %= 9;
	return n ? n : 9;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int n;
	cin >> n;

	int m = max (n, 100);
	vector<int> v (m+1);
	for (int i=1; i<=m; ++i)
		v[i] = root(i);

	vector<int> cnt (10);
	for (int i=1; i<=n; ++i)
		++cnt[v[i]];

	int good = 0;
	for (int a=1; a<=n; ++a)
		for (int b=a; a*1ll*b<=n; ++b)
			if (v[a*b] == v[ v[a] * v[b] ])
				good += a==b ? 1 : 2;

	long long total = 0;
	for (int va=0; va<10; ++va)
		for (int vb=0; vb<10; ++vb)
			total += cnt[va] * 1ll * cnt[vb] * cnt[ v[va*vb] ];

	cout << total - good;

}