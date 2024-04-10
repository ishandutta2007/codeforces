#include <iostream>
#include <algorithm>
using namespace std;

long long a[100009], b[100009], maxn;

int main() {
	for (int i = 0; i < 14; i++) cin >> a[i];
	for (int i = 0; i < 14; i++) {
		if (a[i] == 0) continue;
		for (int j = 0; j < 14; j++) { if (i != j) b[j] = a[j]; else b[j] = 0; }
		for (int j = 0; j < 14; j++) {
			long long V = (a[i] + 13 - j) / 14;
			b[(i + j + 1) % 14] += V;
		}
		long long res = 0;
		for (int j = 0; j < 14; j++) {
			if (b[j] % 2 == 0) res += b[j];
		}
		maxn = max(maxn, res);
	}
	cout << maxn << endl;
	return 0;
}