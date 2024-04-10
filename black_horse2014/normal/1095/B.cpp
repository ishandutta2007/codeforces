#include <bits/stdc++.h>
using namespace std;

const int N = 110000;
int a[N];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	cout << min(a[n - 1] - a[1], a[n] - a[2]) << endl;
	return 0;
}