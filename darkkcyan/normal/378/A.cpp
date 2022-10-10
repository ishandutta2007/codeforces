#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b; cin >> a >> b;
	int ans[3] = {0};
	for (int i = 1; i <= 6; ++i) {
		int x = abs(a - i), y = abs(b - i);
		if (x > y) ++ ans[2];
		else if (x < y) ++ans[0];
		else ++ans[1];
	}
	for (int i = 0; i < 3; ++i)
		cout << ans[i] << ' ';
	return 0;
}