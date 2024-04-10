#include <iostream>

using namespace std;

int f[1000006];
int r[1000005];
int l[1000005];

int main() {
	ios::sync_with_stdio(0);

	fill(r, r + 1000005, 1e9);
	fill(r, r + 1000005, -(1e9));
	fill(f, f + 1000005, 0);

	int n;
	cin >> n;

	int maxf = 0;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		++f[k];
		if (f[k] == 1)
			l[k] = i;
		r[k] = i;
//		cout << "setting " << k << " to " << i << endl;
		maxf = max(f[k], maxf);
	}

	int dist = 1e9;
	int ai = -1;
	for (int i = 0; i < 1000005; ++i) {
		if (f[i] == maxf) {
			if (r[i] - l[i] + 1 < dist) {
				dist = r[i] - l[i] + 1;
				ai = i;
			}
		}
	}
	cout << l[ai] + 1 << " " << r[ai] + 1 << "\n";

	return 0;
}