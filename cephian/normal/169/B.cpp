#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	string a, s;
	cin >> a >> s;
	sort(s.rbegin(), s.rend());
	int j = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (j == s.size())
			break;
		if (s[j] > a[i]) {
			a[i] = s[j];
			++j;
		}
	}
	cout << a << "\n";
	return 0;
}