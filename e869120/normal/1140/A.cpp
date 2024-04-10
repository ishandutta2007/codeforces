#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100009], maxn, cnt;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; maxn = max(maxn, a[i]);
		if (maxn == i) cnt++;
	}
	cout << cnt << endl;
	return 0;
}