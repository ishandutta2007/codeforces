#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
int a[320009], n, k;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) { cin >> a[i]; a[i] ^= 1; }
	for (int i = 1; i <= n; i++)a[i] += a[i - 1]; a[n + 1] = (1 << 30);
	int maxn = 0, maxid = -1;
	for (int i = 0; i < n; i++) {
		int pos1 = upper_bound(a, a + n + 1, a[i] + k) - a;
		if (maxn < pos1 - i - 1) {
			maxn = pos1 - 1 - i;
			maxid = i;
		}
	}
	for (int i = n; i >= 1; i--)a[i] = a[i] - a[i - 1];
	for (int i = 1; i <= n; i++)a[i] ^= 1;
	cout << maxn << endl;
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (i >= 2)cout << ' ';
		if (a[i] == 1)cout << a[i];
		else if (i <= maxid)cout << a[i];
		else if (c == k)cout << a[i];
		else { cout << "1"; c++; }
	}
	cout << endl;
	return 0;
}