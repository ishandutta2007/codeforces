#include <iostream>
using namespace std;

int main() {
	int n, t;
	string s;
	cin >> n >> t >> ws >> s;
	while (t --) {
		for (int i = 0; i < n - 1; ++i) {
			if (s[i] == 'B' and s[i + 1] == 'G') {
				swap(s[i], s[i + 1]);
				++i;
			}
		}
	}
	cout << s;
	return 0;
}