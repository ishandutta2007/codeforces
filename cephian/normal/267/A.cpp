#include <iostream>
#include <algorithm>

using namespace std;

int ans = 0;
int get(int a, int b) {
	if (b == 0)
		return 0;
	return get(b, a % b) + a / b;
}

int main() {
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		if (a < b)
			swap(a, b);
		cout << get(a, b) << "\n";
	}

	return 0;
}