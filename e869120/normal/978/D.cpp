#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long a[100009], b[100009], n, minx = (1LL << 60);

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			for (int k = 1; k <= n; k++) b[k] = a[k];
			b[1] += i; b[2] += j;

			long long G = b[1], I = b[2] - b[1], sum = 0;
			if (i != 0) sum++;
			if (j != 0) sum++;
			for (int k = 2; k <= n; k++) {
				G += I;
				if (b[k] == G) continue;
				else if (abs(b[k] - G) == 1) sum++;
				else sum = (1LL << 60);
			}
			minx = min(minx, sum);
		}
	}
	if (minx == (1LL << 60)) minx = -1;
	cout << minx << endl;
	return 0;
}