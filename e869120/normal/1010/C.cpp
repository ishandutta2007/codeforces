#include <iostream>
#include <algorithm>
using namespace std;

int n, k, a[100009], maxn = 0;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i <= k; i++) {
		if (k%i != 0) continue;
		int sum = 0;
		for (int j = 0; j < n; j++) { if (a[j] % i != 0) sum++; }
		if (sum == 0) maxn = max(maxn, i);
	}
	cout << k / maxn << endl;
	for (int i = 0; i < k; i += maxn) { if (i) cout << " "; cout << i; }cout << endl;
	return 0;
}