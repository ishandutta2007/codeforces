#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int ans = 0;

	string num;
	cin >> num;
	for (int i = 0; i < num.size(); ++i) {
		if (num[i] == '7') {
			ans += 2 * (1 << (num.size() - 1 - i));
		} else {
			ans += (1 << (num.size() - 1 - i));
		}
	}
	cout << ans << "\n";

	return 0;
}