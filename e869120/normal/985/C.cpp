#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, k, l, a[100009], s, cnt1, cnt2, minx = 1000000000; vector<long long>x[100009];

int main() {
	cin >> n >> k >> l;
	for (int i = 0; i < n*k; i++) { cin >> a[i]; minx = min(minx, a[i]); }
	sort(a, a + (n*k));
	for (int i = 0; i < n*k; i++) { if (a[i] <= minx + l) s++; }

	if (s < n) { cout << "0" << endl; return 0; }

	for (int i = 0; i < n*k; i++) {
		if (i < s) {
			int Z = n - cnt2;
			if ((s - i) == Z) {
				x[cnt2].push_back(a[i]);
				cnt2++;
			}
			else {
				while (x[cnt1].size() == k) { cnt1++; }
				x[cnt1].push_back(a[i]); if (x[cnt1].size() == 1) cnt2++;
			}
		}
		else {
			while (x[cnt1].size() == k) { cnt1++; }
			x[cnt1].push_back(a[i]);
		}
	}
	long long sum = 0; for (int i = 0; i < n; i++) sum += x[i][0];
	cout << sum << endl;
	return 0;
}