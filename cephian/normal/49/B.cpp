#include <iostream>
#include <algorithm>

using namespace std;

int convert(string num, int base) {
	int ans = 0;
	for (int i = 0; i < num.size(); ++i) {
		ans *= base;
		ans += num[i] - '0';
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);

	string a, b;
	cin >> a >> b;

	int base = 0;
	for (int i = 0; i < a.size(); ++i)
		base = max(base, a[i] - '0');

	for (int i = 0; i < b.size(); ++i)
		base = max(base, b[i] - '0');
	++base;

	int sum = convert(a, base) + convert(b, base);
	string ans;
	while (sum > 0) {
		ans += (char) (sum % base);
		sum /= base;
	}
	cout << ans.size() << "\n";

	return 0;
}