#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <functional>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

int n, m, a[1009], c[1009], d;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		c[a[i]]++;
		int s = 1; for (int j = 1; j <= n; j++) { if (c[j] == 0) s = 0; }
		if (s == 1) {
			d++;
			for (int j = 1; j <= n; j++) c[j]--;
		}
	}
	cout << d << endl;
	return 0;
}