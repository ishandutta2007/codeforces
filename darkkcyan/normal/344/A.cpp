#include <iostream>
using namespace std;

int main() {
	int n;
	string s1, s2;
	int ans = 0;
	cin >> n;
	while (n -- ) {
		cin >> s2;
		ans += s2 != s1;
		s1 = s2;
	}
	cout << ans;
	return 0;
}