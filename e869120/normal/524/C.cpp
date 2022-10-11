#include<iostream>
#include<algorithm>
using namespace std;
int n, a[100009], q, g, K;
int main() {
	cin >> n >> K; for (int i = 0; i < n; i++)cin >> a[i]; sort(a, a + n);
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> g; int minx = 1000;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= 20; k++) {
				int V = g - k*a[j];
				for (int l = 1; l <= 20; l++) {
					if (V%l != 0)continue;
					int U = V / l;
					int pos1 = lower_bound(a, a + n, U) - a;
					if (U == a[pos1])minx = min(minx, k + l);
				}
			}
		}
		if (minx > K)minx = -1;
		cout << minx << endl;
	}
	return 0;
}