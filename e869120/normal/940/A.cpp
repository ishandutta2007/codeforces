#include <iostream>
#include <algorithm>
using namespace std;

int n, d, a[10009], maxn = 0;

int main() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i <= 100; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (i <= a[j] && a[j] <= i + d) sum++;
		}
		maxn = max(maxn, sum);
	}
	cout << n - maxn << endl;
	return 0;
}