#include<iostream>
using namespace std;
int n, k, p, a[10005], b[1 << 14];
int main() {
	cin >> n >> k;
	for (int i = 0; i < 16384; i++) {
		for (int j = 0; j < 14; j++) { if ((i / (1 << j)) % 2 == 1)b[i]++; }
	}
	for (int i = 0; i < n; i++) { cin >> p; a[p]++; }
	long long cnt = 0; for (int i = 0; i <= 10000; i++) { for (int j = 0; j <= 10000; j++) { if (b[i^j] == k)cnt += 1LL * a[i] * a[j]; } }
	if (k == 0)cnt -= n; cnt /= 2;
	cout << cnt << endl;
	return 0;
}