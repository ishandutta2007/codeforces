#include <iostream>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	string s1, s2, s3;
	for (int i = 0; i < m; ++i) {
		s1 += '#';
		s2 += '.';
		s3 += '.';
	}
	s2[m - 1] = s3[0] = '#';
	for (int i = 1; i < n; i += 2) {
		cout << s1 << '\n';
		if (i & 2) cout << s3;
		else cout << s2;
		cout << '\n';
	}
	cout << s1;
	return 0;
}