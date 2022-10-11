#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int n, k, a[10000], b[10000], maxn = 1e9, maxid = 0;
int main() {
	cin >> n >> k; for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 0; i <= k; i++) {
		b[1] = max(i, a[1]);
		for (int j = 2; j <= n; j++)b[j] = max(k - b[j - 1], a[j]);
		int sum = 0; for (int j = 1; j <= n; j++)sum += (b[j] - a[j]);
		if (maxn > sum) { maxn = sum; maxid = i; }
	}
	b[1] = max(maxid, a[1]);
	for (int j = 2; j <= n; j++)b[j] = max(k - b[j - 1], a[j]);
	cout << maxn << endl;
	for (int j = 1; j <= n; j++) { if (j >= 2)cout << ' '; cout << b[j]; }cout << endl;
	return 0;
}