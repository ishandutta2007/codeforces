#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, a[100009];

int main() {
	cin >> n;
	for (int i = 0; i < n / 2; i++) cin >> a[i];
	sort(a, a + (n / 2));
	int s1 = 0; for (int i = 1; i <= n; i += 2) s1 += abs(a[i / 2] - i);
	int s2 = 0; for (int i = 2; i <= n; i += 2) s2 += abs(a[(i - 2) / 2] - i);
	cout << min(s1, s2) << endl;
	return 0;
}