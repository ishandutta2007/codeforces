#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int t;
	for (t = 0; t <= n; t += m) {
		int a = n - t;
		int b = t - a;
		if (a >= 0 and b >= 0) break;
	}
	if (t > n)  cout << -1;
	else cout << t;
	return 0;
}